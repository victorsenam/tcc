#include "test_helpers.h"

void TEST (bool cond, std::string file, std::string msg, std::function< void() > callback) {
	printf("[%s] %s\n", file.c_str(), msg.c_str());
	if (cond)
		return;

	printf("FALHA\n");
	fflush(stdout);
	callback();
	exit(1);
}

void TEST (bool cond, std::string file, std::string msg) {
	TEST(cond, file, msg, [] ()->void { });
}

std::function< void() > TEST_compare_vectors_int (const std::vector<int> & a, const std::vector<int> & b) {
    return [a, b] ()->void {
        printf("Esperado:\n\t");
        for (unsigned i = 0u; i < a.size(); i++)
            printf(" (%d,%d)", a[i].x, a[i].y);
        printf("\n");
        printf("Fornecido:\n\t");
        for (unsigned i = 0u; i < b.size(); i++)
            printf(" (%d,%d)", b[i].x, b[i].y);
        printf("\n");
    };
}
