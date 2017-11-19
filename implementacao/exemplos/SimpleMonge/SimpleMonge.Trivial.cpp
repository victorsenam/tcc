/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <vector>

int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::vector<double> > A(n, std::vector<double>(m));
	std::vector<int> R(n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lf", &A[i][j]);
			if (A[i][j] < A[i][R[i]])
				R[i] = j;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%f\n", A[i][R[i]]);
}
