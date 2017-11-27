/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <cmath>
#include <vector>

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
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &v[i].x, &v[i].y);
	}

	for (int i = 0; i < n; i++) {
		double mx = 0;
		for (int j = 0; j < n; j++)
			mx = std::max(mx, d(v[i],v[j]));
		printf("%f\n", mx);
	}
}
