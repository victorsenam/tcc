/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <cmath>
#include "../../algoritmos/EnvelopeConvexoLinear.h"

#include <iostream>

int main () {
	int n, k;
	scanf("%d %d", &n, &k);

	std::vector<int> a(n);
	std::vector<long long> sum_a(n+1,0);
	std::vector<long long> sum_ai(n+1,0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum_a[i+1] = sum_a[i] + a[i];
		sum_ai[i+1] = sum_ai[i] + i*a[i];
	}

	std::vector<long long> E(n+1);
	std::vector<long long> alpha(n+1);
	std::vector<long long> beta(n+1);

	for (int i = n; i >= 0; i--) {
		E[i] = sum_ai[n] - sum_ai[i] - i*(sum_a[n] - sum_a[i]);
	}

	for (int l = 2; l <= k; l++) {
		std::vector<long long> alpha(n+1);
		std::vector<long long> beta(n+1);
		EnvelopeConvexoLinear Envelope(alpha,beta,n+1);
		for (int j = 0; j <= n; j++) {
			alpha[j] = -sum_a[j];
			beta[j] = E[j] + sum_ai[j];
		}
		
		E[n] = 0;
		for (int i = n-1; i >= 0; i--) {
			Envelope.Remove();
			Envelope.Insere(i+1);
			int j = Envelope.Calcula();
			E[i] = beta[j] - sum_ai[i] - (-alpha[j] - sum_a[i])*i;
		}
	}

	printf("%lld\n", E[0]);
}
