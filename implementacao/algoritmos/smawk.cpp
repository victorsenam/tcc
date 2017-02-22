/* Implementação do Algoritmo SMAWK */
#include "smawk.h"

void smawk_reduce (std::list<int> & col, const std::vector<std::vector<int> > & mat, int p) {
    int k = 0;
    int n = mat.size();
    std::list<int>::iterator it = col.begin();
    int sz = col.size();
    
    while (sz > (n+p-1)/p) {
        if (mat[p*k][*it] > mat[p*k][*next(it)]) {
            if (p*(k+1) < n) {
                it = std::next(it);
                k++;
            } else {
                col.erase(std::next(it));   
                sz--;
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
            sz--;
        }
    }
}

void smawk (std::vector<int> & res, const std::vector<std::vector<int> > & mat, std::list<int> col, int p) {
    smawk_reduce(col, mat, p);
    int n = mat.size();
    if (p >= n) {
        res[0] = *(col.begin());
    } else {
        smawk(res, mat, col, p*2);

        for (int i = p; i < n; i += 2*p)
            res[i] = res[i-p];
        std::list<int>::const_iterator it = col.begin();
        for (int i = p; i < n; i += 2*p) {
            while (it != col.end() && (i + p >= n || *it <= res[i+p])) {
                if (mat[i][*it] > mat[i][res[i]])
                    res[i] = *it;
                it = next(it);
            }
        }
    }
}
