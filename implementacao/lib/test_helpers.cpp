#include "test_helpers.h"

void TEST (bool cond, std::string file, std::string msg) {
	TEST(cond, file, msg, [] ()->void {
		exit(1);
	});
}
