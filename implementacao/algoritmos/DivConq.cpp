#include "DivConq.h"

void DivConq (std::function< double(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & res) {
    if (rs > rt)
        return;

    int l = (rs + rt)/2;

    res[l] = cs;
    for (int j = cs + 1; j <= ct; j++) {
        if (A(l,j) < A(l,res[l]))
            res[l] = j;
    }

    DivConq(A, rs, l-1, cs, res[l], res);
    DivConq(A, l+1, rt, res[l], ct, res);
}

std::vector<int> DivConq (std::function< double(int,int) > A, int n, int m) {
    std::vector<int> res(n);
    DivConq(A, 0, n-1, 0, m-1, res);
    return res;
}
