#ifndef TCC_DivConq
#define TCC_DivConq

#include <vector>
#include <functional>

void DivConq (std::function< int(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & r);
std::vector<int> DivConq (std::function< int(int,int) > A, int n, int m);

#endif
