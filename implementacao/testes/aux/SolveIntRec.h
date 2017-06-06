#ifndef TCC_FindRowMin
#define TCC_FindRowMin

#include <vector>
#include <functional>

std::vector<std::vector<double> > SolveIntRec (std::function< double(int,int) > C, int n);

#endif
