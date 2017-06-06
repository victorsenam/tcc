#ifndef TCC_FindRowMin
#define TCC_FindRowMin

#include <vector>
#include <functional>

std::vector<int> FindRowMin (std::function< double(int,int) > A, int n, int m);

#endif
