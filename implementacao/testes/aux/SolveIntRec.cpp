#include "SolveIntRec.h"

std::vector<std::vector<double> > SolveIntRec (std::function< double(int,int) > C, int n) {
    std::vector<std::vector<double> > A(n, std::vector<double>(n,1./0.));

    for (int i = n-1; i >= 0; i--) {
        A[i][i] = C(i,i);
        for (int j = i+1; j < n; j++) {
            for (int k = i+1; k <= j; k++) {
                double v = A[i][k-1] + A[k][j];
                if (v < A[i][j])
                    A[i][j] = v;
            }
            A[i][j] += C(i,j);
        }
    }
    
    return A;
}
