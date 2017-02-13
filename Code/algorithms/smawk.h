#ifndef CODE_SMAWK
#define CODE_SMAWK

#include <iostream>
#include <vector>
#include <list>

void smawk_reduce (std::list<int> & col, const std::vector<std::vector<int> > & mat, int p);
void smawk (std::vector<int> & res, const std::vector<std::vector<int> > & mat, std::list<int> col, int p);

#endif
