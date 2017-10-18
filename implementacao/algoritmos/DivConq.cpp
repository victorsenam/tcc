#include "DivConq.h"

DivConq::DivConq (std::function< double(int,int) > A, int n, int m) {
	::A = A;
	::n = n;
	::m = m;
}

vector<int> DivConq::FindRowMinima () {
	vector<int> R(n);
	FindRowMinima(R, 0, n-1, 0, m-1);
	return R;
}

void DivConq::FindRowMinima (int rs, int rt, int cs, int ct, vector<int> & R) {
	if (rs <= rt) {
		int l = (rs + rt)/2;

		R[l] = cs;
		for (int j = cs + 1; j <= ct; j++) {
			if (A(l,j) < A(l,R[l]))
				R[l] = j;
		}

		DivConq(A, rs, l-1, cs, R[l], R);
		DivConq(A, l+1, rt, R[l], ct, R);
	}
}
