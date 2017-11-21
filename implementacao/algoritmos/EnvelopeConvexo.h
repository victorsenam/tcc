/**
	Envelope convexo
	Seção 7

	Envelope sobre uma matriz totalmente monótona convexa triangular superior em 0 online nas linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/

#ifndef TCC_EnvelopeConvexo
#define TCC_EnvelopeConvexo

#include <functional>
#include <queue>

/**
	Envelope sobre uma matriz totalmente monótona convexa triangular superior em 0 online nas linhas.

	A matriz tem como entradas os valores da função A que recebe 3 argumentos, i, j e R[j], onde R[j] é o mínimo da linha j. A matriz deve ser totalmente monótona convexa nas linhas. Os elementos do envelope são guardados em E. Os valores dos mínimos das linhas da matriz A são guardados em V.
**/

class EnvelopeConvexo {
public:
	// Constrói um envelope sobre a matriz A de tamanho n x n
	EnvelopeConvexo(std::function< double(int,int) > A, int n);

	// Descobre o índice de mínimo da coluna i
	int Calcula();

	// Remove a última linha da matriz A
	void Remove();

	// Insere uma coluna disponível no envelope
	void Insere(int j);

protected:
	int n;
	std::function< double(int,int) > A;
	std::deque<int> E;

	// Devolve a intersecção entre as colunas a e b onde a <= b
	virtual int Intersecta(int a, int b);
	
	// Calcula as funções s e t para descritas no texto para o elemento de E apontado por it
	int s(std::deque<int>::iterator it);
	int t(std::deque<int>::iterator it);
};

#endif
