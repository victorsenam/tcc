/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include "../../algoritmos/KnuthYao.h"

int main () {
	int n, m;
	while (scanf("%d %d", &m, &n) != EOF) {
		n++;
		std::vector<int> a(n+1);
		for (int i = 1; i < n; i++)
			scanf("%d", &a[i]);
		a[n] = m;

		KnuthYao Solver([&a] (int i, int j) { return (double) a[j+1] - a[i]; }, n);
		printf("%d\n", (int) Solver.Solve()[0][n-1] - m);
	}
}
