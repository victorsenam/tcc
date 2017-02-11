/* Implementação do Algoritmo SMAWK */
#include <iostream>
#include <vector>
#include <list>

void reduce (std::list<int> & col, const std::vector<std::vector<int> > & mat, int p) {
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
    reduce(col, mat, p);
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

bool naive_check (std::vector<int> & res, const std::vector<std::vector<int> > & mat) {
    bool ok = 1;
    for (int i = 0; i < res.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
            if (mat[i][j] > mat[i][res[i]]) {
                ok = 0;
                res[i] = j;
            }

    return ok;
}

int main () {
    int n, m, sz;
    std::vector<std::vector<int> > mat; // input matrix
    std::vector<int> res; // output (index of row maxima)

    std::list<int> col;

    std::cin >> n >> m;
    sz = m;
    
    mat.resize(n, std::vector<int>(m));
    res.resize(n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> mat[i][j];
    for (int i = 0; i < m; i++)
        col.push_back(i);
    
    smawk(res, mat, col, 1);
    for (int i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < res.size(); i++)
        std::cout << mat[i][res[i]] << " ";
    std::cout << std::endl;
    if (!naive_check(res, mat)) {
        std::cout << "FAIL! Naive result: " << std::endl;
        for (int i = 0; i < res.size(); i++)
            std::cout << mat[i][res[i]] << " ";
        std::cout << std::endl;
    }
}
