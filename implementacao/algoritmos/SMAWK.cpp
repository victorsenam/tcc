#include "SMAWK.h"

std::list<int> Reduce (std::function< int(int,int) > w, int n, int p, std::list<int> col) {
    int k = 0;
    std::list<int>::iterator it = col.begin();

    while (col.size() > unsigned(n + p - 1)/p) {
        if (w(p*k, *it) > w(p*k, *next(it))) {
            if (p*(k+1) < n) {
                it = std::next(it);
                k++;
            } else {
                col.erase(std::next(it));
            }
        } else {
            if (k) {
                k--;
                it = std::prev(it);
                col.erase(std::next(it));
            } else {
                col.erase(it);
                it = col.begin();
            }
        }
    }

    return col;
}

void SMAWK (std::function< int(int,int) > w, int n, int p, const std::list<int> & col, std::vector<int> & res) {
    if (p >= n) {
        res[0] = *(col.begin());
    } else {
        SMAWK(w, n, p+p, Reduce(w, n, p+p, col), res);

        std::list<int>::const_iterator it = col.begin();
        for (int i = p; i < n; i += p+p) {
            res[i] = res[i-p];

            while (it != col.end() && (i + p >= n || *it <= res[i+p])) {
                if (w(i,*it) > w(i,res[i]))
                    res[i] = *it;
                it = next(it);
            }
        }
    }
}

std::vector<int> SMAWK (std::function< int(int,int) > w, int n, int m) {
    std::vector<int> res(n);

    std::list<int> col;
    for (int i = 0; i < m; i++)
        col.push_back(i);

    smawk(w, n, 1, Reduce(w, n, 1, col), res);
    return res;
}
