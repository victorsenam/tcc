#ifndef TCC_FindRowMin
#define TCC_FindRowMin

#include <vector>
#include <functional>

std::vector<int> FindRowMin (std::function< int(int,int) > A, int n, int m);

#endif
