/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include "../../algoritmos/DivConq.h"
#include <cstdio>
#include <cmath>

struct point {
	double x, y;

	point () : x(0), y(0) {}
	point (double a, double b) : x(a), y(b) {}

	point operator - () {
		return point(-x,-y);
	}
};

inline double sq (double x) {
	return x*x;
}

inline double d (point a, point b) {
	return sq(a.x - b.x) + sq(a.y - b.y);
}

int main () {
	int n;
	scanf("%d", &n);

	std::vector<point> v(n);
	double C = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &v[i].x, &v[i].y);
		C = std::max(C, d(v[i],-v[i]));
	}

	std::function< double(int,int) > f([C,&v,n] (int i, int j) {
		if (j <= i) return C*(i-j);
		if (i + n <= j) return C*(j - n - i);
		return -d(v[i%n],v[j%n]);
	});

	DivConq Solver(f, n, 2*n-1);
	std::vector<int> R = Solver.FindRowMinima();
	
	for (int i = 0; i < n; i++)
		printf("%f\n", -f(i,R[i]));
}
