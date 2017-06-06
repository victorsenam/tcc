#include "FindRowMin.h"

std::vector<int> FindRowMin (std::function< int(int,int) > A, int n, int m) {
    std::vector<int> r(n);

    for (int i = 0; i < n; i++) {
        r[i] = 0;
        for (int j = 1; j < m; j++)
            if (A(i,r[i]) > A(i,j))
                r[i] = j;
    }

    return r;
}
