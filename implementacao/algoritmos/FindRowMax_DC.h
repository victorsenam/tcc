#ifndef TCC_divisaoeconquista
#define TCC_divisaoeconquista

#include <vector>
#include <functional>

void FindRowMax_DC (std::function< int(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & r);
std::vector<int> FindRowMax_DC (std::function< int(int,int) > A, int n, int m);

#endif
