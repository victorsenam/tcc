#include "DivConq.h"

DivConq::DivConq (std::function< double(int,int) > A, int n, int m) {
	this->A = A;
	this->n = n;
	this->m = m;
}

std::vector<int> DivConq::FindRowMinima () {
	std::vector<int> R(n);
	FindRowMinima(0, n-1, 0, m-1, R);
	return R;
}

void DivConq::FindRowMinima (int rs, int rt, int cs, int ct, std::vector<int> & R) {
	if (rs <= rt) {
		int l = (rs + rt)/2;

		R[l] = cs;
		for (int j = cs + 1; j <= ct; j++) {
			if (A(l,j) < A(l,R[l]))
				R[l] = j;
		}

		FindRowMinima(rs, l-1, cs, R[l], R);
		FindRowMinima(l+1, rt, R[l], ct, R);
	}
}
