#include "EnvelopeConvexo.h"

EnvelopeConvexo::EnvelopeConvexo (std::function< double(int,int,double) > A, int n) {
	::A = A;
	::n = n;
	V.resize(n);
}

void EnvelopeConvexo::Insere (int j) {
	if (!E.empty() && A[n-1][E.back().j] <= A[n-1][j])
		return;
	while (!E.empty() && A[E.back().s][E.back().j] > A[E.back().s][j])
		E.pop_back();

	Elemento el(j,0);
	if (!E.empty())
		el.s = Intersecta(E.back().j,j);
	E.push_back(el);
}

void EnvelopeConvexo::Calcula (int i) {
	int l = 0, r = E.size() - 1;
	while (l < r) {
		int p = (l+r)/2;
		if (E[p].s <= i)
			r = p;
		else
			l = p+1;
	}
	return l;
}

EnvelopeConvexo::Elemento (int i_j, int i_s) : j(i_j), s(i_s) {}

int EnvelopeConvexo::Intersecta (int a, int b) {
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
