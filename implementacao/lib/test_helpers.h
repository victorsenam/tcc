#ifndef TCC_LIB_TEST
#define TCC_LIB_TEST

#include <cassert>
#include <string>
#include <functional>
#include <vector>

void TEST (bool cond, std::string file, std::string msg, std::function< void() > callback);
void TEST (bool cond, std::string file, std::string msg);

std::function< void() > TEST_compare_vectors_int (const std::vector<int> & a, const std::vector<int> & b);

#endif
