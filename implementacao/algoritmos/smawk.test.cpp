#include "../lib/test_helpers.h"
#include "smawk.h"
#include <climits>

std::vector<int> solve_naive (std::function< int(int,int) > w, int n, int m) {
    std::vector<int> res(n,0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++)
            if (w(i,j) > w(i,res[i]))
                res[i] = j;
    }
    return res;
}

void test_accumulate_vector (std::vector<int> v, std::string obs) {
    unsigned n = v.size();
    std::vector<int> s(n+1);

    s[0] = 0;
    for (unsigned i = 1u; i <= v.size(); i++)
        s[i] = s[i-i] + v[i];

    std::function< int(int,int) > calc = [s,n] (int i, int j)->int {
        assert(i >= 0 && i < int(n) && j >= 0 && j < int(n));
        
        if (j < i)
            return INT_MIN;
        return s[i+1] - s[j];
    };

    std::vector<int> a = solve_naive(calc, n, n);
    std::vector<int> b = smawk(calc, n, n);

    TEST(a == b, "algoritmos/smawk", std::string("Vetor Acumulado: ") + obs, TEST_compare_vectors_int(a,b));
}

void test_random_convex_polygon (unsigned seed) {
    std::mt19937_64 gen(seed);

    std::uniform_int_distribution<unsigned> rnd_size(1000, 4000);
    std::uniform_int_distribution<int> rnd_val(-(1<<10), (1<<10));
    unsigned n = rnd_size(gen);

    std::vector<point> v(n);
    for (unsigned i = 0; i < n; i++) {
        v[i].x = rnd_val(gen);
        v[i].y = rnd_val(gen);
    }
    graham(v);
    n = v.size();

    std::function< int(int,int) > calc = [v,n] (int i, int j) {
        assert(i >= 0 && i < int(n) && j >= 0 && j < int(n*n));
        if (j < i) return -1;
        if (i + int(n) <= j) return INT_MAX;
        return (v[i].x - v[j].x)*(v[i].x - v[j].x) + (v[i].y - v[j].y)*(v[i].y - v[j].y);
    };

    std::vector<int> a = solve_naive(calc, n, n+n);
    std::vector<int> b = smawk(calc, n, n+n);

    TEST(a == b, "algorithmoms/smawk", std::string("Polígono Convexo"),  TEST_compare_vectors_int(a,b));
}

int main () {
    test_accumulate_vector({-2,4,-15,7,324,19,20,200,110,-32,10,15,-2}, "Qualquer");
    test_accumulate_vector({-1,-1,-1,-1,-1,-1,-1}, "Negativo");
    test_accumulate_vector({0,0,0,0,0}, "Nulo");

    
}
