#ifndef TCC_smawk
#define TCC_smawk

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <random>

#include "../lib/graham.h"

std::list<int> smawk_reduce (std::function< int(int,int) > w, int n, int p, std::list<int> col);
void smawk (std::function< int(int,int) > w, int n, int p, const std::list<int> & col, std::vector <int> & res);
std::vector<int> smawk (std::function< int(int,int) > w, int n, int m);

#endif
