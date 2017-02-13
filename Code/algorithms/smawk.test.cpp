#include "smawk.h"

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
