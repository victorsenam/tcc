/**
	Aplicação de envelope convexo
	Seção 7

	Resolve o Problema 7.3 utilizando a estrutura de envelope convexo. Note que o problema pode ser resolvido com o envelope desde que as entradas da triangular superior da matriz C formem uma matriz triangular superior em 0 Monge convexa.

	Entrada:
	Na primeira linha da entrada é dado o inteiro n. Nas n linhas seguintes são dados n inteiros.  O j-ésimo número da i-ésima linha destas é a entrada C[i][j].

	Saída:
	Na primeira linha da saída devem ser dados os valores do vetor E de resposta. Primeiro o valor E[1], depois E[2] e assim por diante até o E[n].

	Exemplo de entrada:
	3
	1 1 2
	1 1 1
	1 1 1

	Exemplo de saída:
	2 1 0
**/


#include <cstdio>
#include "../../algoritmos/EnvelopeConvexo.h"

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
	EnvelopeConvexo Envelope(B,n);

	E[n-1] = 0;
	for (int i = n-2; i >= 0; i--) {
		Envelope.Remove();
		Envelope.Insere(i+1);
		int j = Envelope.Calcula();
		E[i] = B(i,j);
	}

	for (int i = 0; i < n; i++)
		printf("%.6f ", E[i]);
	printf("\n");
}
