#ifndef TCC_divisaoeconquista
#define TCC_divisaoeconquista

#include <vector>
#include <functional>

void divconq (std::function< int(int,int) > A, int ls, int lt, int cs, int ct, std::vector<int> & r);
std::vector<int> divconq (std::function< int(int,int) > A, int n, int m);

#endif
