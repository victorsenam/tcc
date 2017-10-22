/**
	Exemplo de aplicação de algoritmos em matrizes Monge
	Seção 2

	Resolve o problema proposto no final da Seção 3 da maneira trivial, sem utilizar a monotonicidade do problema.

	Entrada:
	Na primeira linha da entrada são dados os inteiros k e n (nesta ordem). Na segunda linha são dados os reais v_1, v_2, ..., v_n separados por espaço.

	Saída:
	Na primeira linha da saída deve ser dado o valor mínimo da função otimizada pelo problema.

	Exemplo de entrada:
	3 7
	13 7 4 9 14 2 5

	Exemplo de saída:
	13
**/

#include <cstdio>
#include <vector>

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
		std::vector<double> next_E(n+1);
		// Calcula a linha l da matriz E
		for (int i = 1; i <= n; i++) {
			next_E[i] = 1./0.;
			for (int j = i; j <= n; j++)
				next_E[i] = std::min(next_E[i], A(a,b,i,j) + E[j]);
		}
		E = next_E;
		printf("%f\n", E[1]);
	}
}
