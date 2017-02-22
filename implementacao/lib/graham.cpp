#include "graham.h"
#include <algorithm>

void graham (std::vector<point> & v) {
    for (unsigned int i = 1; i < v.size(); i++) {
        if (v[i] < v[0]) {
            std::swap(v[i],v[0]);
        }
    }

    point anc = v[0];

    std::sort(v.begin()+1, v.end(), [anc] (point i, point j)->bool {
        long long ar = ((anc-i)^(anc-j));
        if (ar == 0)
            return i < j;
        return ar > 0;
    });

    unsigned int sz = 1u;
    for (unsigned int i = 1u; i < v.size(); i++) {
        while (sz > 1u && ((v[sz-1]-v[sz-2])^(v[i]-v[sz-2])) <= 0)
            sz--;
        v[sz] = v[i];
        sz++;
    }
    v.resize(sz);
}
