#ifndef TCC_SMAWK
#define TCC_SMAWK

#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <random>

#include "../lib/graham.h"

std::list<int> Reduce (std::function< int(int,int) > w, int n, int p, std::list<int> col);
void SMAWK (std::function< int(int,int) > w, int n, int p, const std::list<int> & col, std::vector <int> & res);
std::vector<int> SMAWK (std::function< int(int,int) > w, int n, int m);

#endif
