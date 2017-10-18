/**
	Exemplo de aplicação de algoritmos em matrizes Monge
	Seção 2

	Resolve o problema proposto no final da Seção 2 usando o algoritmo SMAWK.

	Entrada:
	Na primeira linha da entrada são dados os inteiros k e n (nesta ordem). Na segunda linha são dados os reais v_1, v_2, ..., v_n separados por espaço.

	Saída:
	Na primeira linha da saída deve ser dado o valor mínimo da função otimizada pelo problema.

	Exemplo de entrada:
	3 7
	13 7 4 9 14 2 5

	Exemplo de saída:
	1010
**/


#include "../../algoritmos/SMAWK.h"
#include <cstdio>

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
