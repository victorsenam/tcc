#ifndef TCC_LIB_TEST
#define TCC_LIB_TEST

#include <cassert>
#include <string>
#include <functional>

template<typename Function>
void TEST (bool cond, std::string file, std::string msg, Function callback) {
	if (cond) return;

	printf("Falha em %s: %s\n", file.c_str(), msg.c_str());
	fflush(stdout);
	callback();
}

void TEST (bool cond, std::string file, std::string msg);

#endif
