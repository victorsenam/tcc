/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <climits>
#include <vector>

int main () {
	int n, m;
	while (scanf("%d %d", &m, &n) != EOF) {
		n++;
		std::vector<int> a(n+1);
		for (int i = 1; i < n; i++)
			scanf("%d", &a[i]);
		a[n] = m;
		std::vector<std::vector<int> > A(n, std::vector<int>(n));
		
		for (int i = n-1; i >= 0; i--) {
			A[i][i] = 0;
			for (int j = i + 1; j < n; j++) {
				A[i][j] = INT_MAX;
				for (int k = i+1; k <= j; k++)
					A[i][j] = std::min(A[i][j], A[i][k-1] + A[k][j]);
				A[i][j] += a[j+1] - a[i];
			}
		}
		printf("%d\n", A[0][n-1]);
	}
}
