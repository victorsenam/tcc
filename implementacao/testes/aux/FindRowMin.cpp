#include "FindRowMin.h"

std::vector<int> FindRowMin (std::function< int(int,int) > A, int n, int m) {
    std::vector<int> res(n);

    for (int i = 0; i < n; i++) {
        res[i] = 0;
        for (int j = 1; j < m; j++)
            if (A(i,j) < A(i,res[i]))
                res[i] = j;
    }

    return res;
}
