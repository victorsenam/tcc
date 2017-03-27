#include "divisaoeconquista.h"

void FindRowMax_DC (std::function< int(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & r) {
    int l = (rt - rs)/2;

    r[l] = cs;
    for (int j = cs + 1; j <= ct; j++) {
        if (A(l,j) > A(i,r[l]))
            r[l] = j;
    }

    if (l > rs)
        divconq(A, rs, l-1, cs, r[l], r);
    if (l < rt)
        divconq(A, l+1, rt, r[l], ct, r);
}

std::vector<int> FindRowMax_DC (std::function< int(int,int) > A, int n, int m) {
    std::vector<int> r(n);

    FindRowMax_DC(A, 0, n-1, 0, m-1, r);
    return r;
}
