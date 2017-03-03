#include "divisaoeconquista.h"

void divconq (std::function< int(int,int) > A, int ls, int lt, int cs, int ct, std::vector<int> & r) {
    int i = (lt - ls)/2;

    r[i] = cs;
    for (int j = cs + 1; j <= ct; j++) {
        if (A(i,j) > A(i,r[i]))
            r[i] = j;
    }

    if (i > ls)
        divconq(A, ls, i-1, cs, r[i], r);
    if (i < lt)
        divconq(A, i+1, lt, r[i], ct, r);
}

std::vector<int> divconq (std::function< int(int,int) > A, int n, int m) {
    std::vector<int> r(n);

    divconq(A, 0, n-1, 0, m-1, r);
    return r;
}
