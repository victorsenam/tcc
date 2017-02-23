#include "point.h"

point::point () {}
point::point (int a, int b) : x(a), y(b) {}

std::function< void() > TEST_compare_vectors_point (const std::vector<point> & a, const std::vector<point> & b) {
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
