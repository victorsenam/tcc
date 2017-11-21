/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <vector>
#include <functional>

double g (double x) {
	return x*x;
}

int main () {
	int n;
	scanf("%d", &n);

	std::vector<double> w(n);
	std::vector<double> a(n+1,0);
	for (int i = 1; i <= n; i++) {
		scanf("%lf", &w[i-1]);
		a[i] = a[i-1] + w[i-1];
	}

	std::vector<double> E(n);
	std::function< double(int,int) > B = [&E,&a] (int i, int j) {
		return g(a[j] - a[i-1]) + E[j];
	};

	E[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		int j = i+1;
		for (int _j = i+2; _j < n; _j++) {
			if (B(i,_j) < B(i,j))
				j = _j;
		}
		E[i] = B(i,j);
	}

	for (int i = 0; i < n; i++)
		printf("%.6f ", E[i]);
	printf("\n");
}
