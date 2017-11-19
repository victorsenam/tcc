/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <vector>

// Calcula g(x)
inline double g (double x) {
	return x*x;
}

// Calcula A[i][j] à partir do vetor a
inline double A (std::vector<double> & a, int i, int j) {
	return (a[j] - a[i])*(a[j] - a[i]);
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
		std::vector<double> next_E(n+1);
		// Calcula a linha l da matriz E
		for (int i = 0; i <= n; i++) {
			next_E[i] = 1./0.;
			for (int j = i; j <= n; j++)
				next_E[i] = std::min(next_E[i], A(a,i,j) + E[j]);
		}
		E = next_E;
	}

	printf("%f\n", E[0]);
}
