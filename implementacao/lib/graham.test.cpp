#include "test_helpers.h"
#include "graham.h"
#include <vector>
#include <algorithm>

void test_all_points_collinear () {
    std::vector<point> a({
        point(-5,-20),
        point(4,16)
    });
    std::vector<point> b({
        point(1,4),
        point(2,8),
        point(4,16),
        point(-5,-20)
    });

    graham(b);

    TEST(a == b, "lib/graham", "Caso Colinear");
}

void test_generic (unsigned seed) {
    std::srand(seed);

    // resposta esperada
    std::vector<point> a({
        point(-8,-3),
        point(-1,-10),
        point(4,-10),
        point(4,-5),
        point(0,-1),
        point(-7,-2)
    });
    // pontos que devem sair
    std::vector<point> b = a;

    std::random_shuffle(b.begin(), b.end());
    graham(b);

    TEST(a == b, "lib/graham", "Caso Convexo", TEST_compare_vectors(a,b));

    b.insert(b.end(), {
        // colineares
        point(-2,-9),
        point(-4,-7),
        point(-5,-6),
        point(2,-10),
        point(3,-10),
        point(4,-7),
        // internos
        point(-5,-3),
        point(2,-7),
        point(1,-8),
        point(-1,-4),
        // repetidos
        point(0,-1)
    });

    std::random_shuffle(b.begin(), b.end());
    graham(b);

    TEST(a == b, "lib/graham", "Caso Genérico", TEST_compare_vectors(a,b));
}

int main () {
    test_all_points_collinear();
    test_generic(7u);
}
