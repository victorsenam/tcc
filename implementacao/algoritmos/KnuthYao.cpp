#include "KnuthYao.h"

KnuthYao::KnuthYao (std::function< double(int,int) > C, int n) {
	::C = C;
	::n = n;
}

std::vector<std::vector<double> > Solve () {
	std::vector<std::vector<double> > A(n, std::vector<double>(n));
	std::vector<std::vector<int> > P(n, std::vector<int>(n));

	for (int i = 0; i < n; i++) {
		A[i][i] = C(i,i);
		P[i][i] = i;
	}

	for (int d = 1; d < n; d++) {
		for (int i = 0; i + d < n; i++) {
			int j = i + d;
			A[i][j] = 1./0.;
			for (int k = P[i][j-1]; k <= P[i+1][j]; k++) {
				double v = A[i][k-1] + A[k][j];
				if (v < A[i][j]) {
					A[i][j] = v;
					P[i][j] = k;
				}
			}
			A[i][j] += C(i,j);
		}
	}

	return A;
}
