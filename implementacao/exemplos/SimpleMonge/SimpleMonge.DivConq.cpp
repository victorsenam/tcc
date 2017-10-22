/**
	Encontrar mínimos de uma matriz Monge convexa

	Encontra os mínimos das linhas de uma matriz A n por m Monge convexa.

	Entrada:
	Na primeira linha da entrada são dados os inteiros n e m (nesta ordem). Nas n linhas seguintes são dadas as entradas da matriz. O j-ésimo número da i-ésima linha é o valor da entrada A[i][j].

	Saída:
	Em i-ésima linha da saída deve ser impresso o valor de mínimo da i-ésima linha.

	Exemplo de entrada:
	3 4
	3 7 10 5
	2 5 7 2
	9 5 6 0

	Exemplo de saída:
	3
	2
	0
**/


#include "../../algoritmos/DivConq.h"
#include <cstdio>


int main () {
	int n, m;
	scanf("%d %d", &n, &m);
	std::vector<std::vector<double> > A(n, std::vector<double>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%lf", &A[i][j]);
	}

	DivConq Solver([A] (int i, int j) { return A[i][j]; }, n, m);
	std::vector<int> R = Solver.FindRowMinima();
	for (int i = 0; i < n; i++)
		printf("%f\n", A[i][R[i]]);
}
