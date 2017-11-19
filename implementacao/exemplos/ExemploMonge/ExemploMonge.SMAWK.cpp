/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include "../../algoritmos/SMAWK.h"
#include <cstdio>

// Calcula g(x)
inline double g (double x) {
	return x*x;
}

// Calcula A[i][j] à partir do vetor a
inline double A (std::vector<double> & a, int i, int j) {
	return g(a[j] - a[i]);
}

int main () {
	int k, n;
	scanf("%d %d", &k, &n);

	std::vector<double> v(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	
	// Calcula o vetor a para facilitar acessos à matriz A
	std::vector<double> a(n+1);
	a[0] = 0.;
	for (int i = 1; i <= n; i++)
		a[i] = a[i-1] + v[i-1];
	
	// Calcula a linha 1 da matriz E
	std::vector<double> E(n+1);
	for (int i = 0; i <= n; i++)
		E[i] = A(a,i,n);

	for (int l = 2; l <= k; l++) {
		// Inicializa a matriz B_l para aplicar o SMAWK
		std::function< double(int,int) > fB( [E,&a] (int i,int j) {
			return A(a,i,j) + E[j];
		});
		SMAWK B(fB, n+1, n+1);
		std::vector<int> R = B.FindRowMinima();

		// Calcula a linha l da matriz E
		for (int i = 0; i <= n; i++)
			E[i] = fB(i,R[i]);
	}

	printf("%f\n", E[0]);
}
