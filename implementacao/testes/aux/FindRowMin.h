#ifndef TCC_FindRowMin
#define TCC_FindRowMin

#include <vector>
#include <functional>

void FindRowMin (std::function< int(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & r);
std::vector<int> FindRowMin (std::function< int(int,int) > A, int n, int m);

#endif
