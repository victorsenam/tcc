/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include "../../algoritmos/DivConq.h"
#include <cstdio>

// Calcula s(i,j) à partir dos vetores a e b
inline double s (std::vector<double> & a, std::vector<double> & b, int i, int j) {
	return b[j] - b[i-1] - (a[j] - a[i-1])*i;
}

// Calcula t(i,j) à partir dos vetores a e b
inline double t (std::vector<double> & a, std::vector<double> & b, int i, int j) {
	return (a[j] - a[i-1])*j - b[j] + b[i-1];
}

// Calcula A[i][j] = c(v[i..j]) à partir dos vetores a e b
inline double A (std::vector<double> & a, std::vector<double> & b, int i, int j) {
	if (i > j) return 0;
	int r = (i+j)/2;
	return s(a,b,i,r) + t(a,b,r+1,j);
}

int main () {
	int k, n;
	scanf("%d %d", &k, &n);

	std::vector<double> v(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	
	// Calcula os vetores a e b para facilitar acessos à matriz A
	std::vector<double> a(n+1);
	std::vector<double> b(n+1);
	a[0] = 0.;
	for (int i = 1; i <= n; i++) {
		a[i] = a[i-1] + v[i-1];
		b[i] = b[i-1] + v[i-1]*i;
	}
	
	// Calcula a linha 1 da matriz E
	std::vector<double> E(n+1);
	for (int i = 1; i <= n; i++) {
		E[i] = A(a,b,i,n);
		printf("%f\n", E[1]);
	}

	for (int l = 2; l <= k; l++) {
		// Inicializa a matriz B_l para aplicar o DivConq
		std::function< double(int,int) > fB( [E,&a,&b] (int i, int j) {
			return A(a,b,i+1,j+1) + E[j+1];
		});
		DivConq B(fB, n, n);
		std::vector<int> R = B.FindRowMinima();

		// Calcula a linha l da matriz E
		for (int i = 1; i <= n; i++)
			E[i] = fB(i-1,R[i-1]);
		printf("%f\n", E[1]);
	}
}
