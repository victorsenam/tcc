/**
	Exemplo de aplicação de algoritmos em matrizes Monge
	Seção 2

	Resolve o problema proposto no final da Seção 2 da maneira trivial, sem utilizar a monotonicidade do problema.

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


#include <cstdio>
#include <vector>

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
			for (int j = 0; j <= n; j++)
				next_E[i] = std::min(next_E[i], A(a,i,j) + E[j]);
		}
		E = next_E;
	}

	printf("%f\n", E[0]);
}
