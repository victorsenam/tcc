#include "EnvelopeConvexo.h"

EnvelopeConvexoLinear::EnvelopeConvexo (std::function< double(int,int,double) > A, int n) {
	::A = A;
	::n = n;
	l = 0;
	V.resize(n);
}

void EnvelopeConvexoLinear::Insere (int j) {
	bool Lost_l = (l >= E.size());

	if (!E.empty() && A[n-1][E.back().j] <= A[n-1][j])
		return;
	while (!E.empty() && A[E.back().s][E.back().j] > A[E.back().s][j]) {
		E.pop_back();
		Lost_l |= (l >= E.size());
	}

	Elemento el(j,0);
	if (!E.empty())
		el.s = Intersecta(E.back().j,j);
	E.push_back(el);
	if (Lost_l)
		l = E.size()-1;
}

int EnvelopeConvexoLinear::Calcula (int i) {
	while (l + 1 < E.size() && A[i][E[l+1].j] < A[i][E[l].j])
		l++;
	return E[l].j;
}

EnvelopeConvexoLinear::Elemento (int i_j, int i_s) : j(i_j), s(i_s) {}

int EnvelopeConvexoLinear::Intersecta (int a, int b) {
	int l = 0, r = n;
	while (l < r) {
		int p = (l+r)/2;
		if (A(p,a,V[a]) <= A(p,b,V[b]))
			l = p+1;
		else
			r = p;
	}
	return l;
}
