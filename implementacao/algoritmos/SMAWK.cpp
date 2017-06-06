#include "SMAWK.h"
#include <iostream>
    
std::list<int> Reduce (std::function< int(int,int) > A, int n, int p, std::list<int> col) {
    int k = 0;
    std::list<int>::iterator it = col.begin();

    while (col.size() > unsigned(n + p - 1)/p) {
        if (A(p*k, *it) > A(p*k, *next(it))) {
            it = col.erase(it);
            it = std::prev(it);
            k -= !!k;
        } else {
            if (p*(k+1) >= n) {
                col.erase(std::next(it));
            } else {
                it = std::next(it);
                k++;
            }
        }
    }

    return col;
}

void SMAWK (std::function< int(int,int) > A, int n, int p, const std::list<int> & col, std::vector<int> & res) {
    if (p >= n) {
        res[0] = *(col.begin());
    } else {
        SMAWK(A, n, p+p, Reduce(A, n, p+p, col), res);

        std::list<int>::const_iterator it = col.begin();
        while (it != col.end() && *it <= res[0])
            it = std::next(it);

        for (int i = p; i < n; i += p+p) {
            res[i] = res[i-p];

            while (it != col.end() && (i + p >= n || *it <= res[i+p])) {
                if (A(i,*it) < A(i,res[i]))
                    res[i] = *it;
                it = std::next(it);
            }
        }
    }
}

std::vector<int> SMAWK (std::function< int(int,int) > A, int n, int m) {
    std::vector<int> res(n);

    if (n > m) {
        std::function< int(int,int) > sA = A;
        int sm = m;
        A = [sA, sm] (int i, int j) {
            if (j >= sm)
                return INT_MAX;
            else
                return sA(i,j);
        };

        m = n;
    }

    std::list<int> col;
    for (int i = 0; i < m; i++)
        col.push_back(i);

    SMAWK(A, n, 1, Reduce(A, n, 1, col), res);
    return res;
}
