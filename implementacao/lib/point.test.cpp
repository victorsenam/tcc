#include "point.h"
#include "test_helpers.h"

int main () {
    point a(2,7), b(4,3);
    point c;

    TEST(a < b, "lib/point", "Comparação Lexicográfica");
    TEST(!(a == b), "lib/point", "Igualdade");

    c = a - b;
    TEST(c == (point(-2,4)), "lib/point", "Subtração");
    
    c = a + b;
    TEST(c == (point(6,10)), "lib/point", "Adição");

    c = a * 3;
    TEST(c == (point(6,21)), "lib/point", "Produto com Escalar");

    TEST((a^b) == -22, "lib/point", "Cross");
    TEST((a*b) == 29, "lib/point", "Dot");
}
