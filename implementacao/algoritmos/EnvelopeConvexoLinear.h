/**
	Envelope convexo linear
	Seção 7

	Envelope linear sobre uma matriz totalmente monótona convexa triangular superior em 0 online nas linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/

#ifndef TCC_EnvelopeConvexoLinear
#define TCC_EnvelopeConvexoLinear

#include "EnvelopeConvexo.h"
#include <functional>
#include <vector>

/**
	Envelope linear sobre uma matriz totalmente monótona convexa triangular superior em 0 online nas linhas.

	A matriz tem como entradas os valores da função A que recebe 3 argumentos, i, j e R[j], onde R[j] é o mínimo da linha j. A matriz deve ser totalmente monótona convexa nas linhas. Os elementos do envelope são guardados em E. Os valores dos mínimos das linhas da matriz A são guardados em V.
**/

class EnvelopeConvexoLinear : public EnvelopeConvexo {
private:
	// Contrói um envelope sobrea a matriz de tamanho n x n dada pelos vetores alpha e beta como descrito em 7.3
	EnvelopeConvexoLinear(std::vector<double> alpha, std::vector<double> beta, int n);

	// Devolve a intersecção entre as colunas a e b onde a <= b
	override int Intersecta(int a, int b);

	// Vetores alpha e beta descritas no texto
	std::vector<double> alpha;
	std::vector<double> beta;
};
