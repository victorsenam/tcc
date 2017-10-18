/**
	Envelope convexo em tempo linear
	Seção 7

	Envelope sobre uma matriz triangular inferior online nas linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/

#ifndef TCC_EnvelopeConvexoLinear
#define TCC_EnvelopeConvexoLinear

#include <functional>
#include <vector>

/**
	Representa um envelope sobre uma matriz triangular inferior online nas linhas.

	A matriz tem como entradas os valores da função A que recebe 3 argumentos, i, j e R[j], onde R[j] é o mínimo da linha j. A matriz deve ser totalmente monótona convexa nas linhas. Os elementos do envelope são guardados em E. Os valores dos mínimos das linhas da matriz A são guardados em V. O inteiro l representa o ponteiro para o elemento da estrutura que ajuda a otimizar a complexidade desta estrutura.
**/

class EnvelopeConvexoLinear {
public:
	// Constrói um envelope sobre a matriz A de tamanho n x n
	EnvelopeConvexo(std::function< double(int,int,double) > A, int n);

	// Insere uma coluna disponível no envelope
	void Insere(int j);

	// Descobre o índice de mínimo da coluna i
	int Calcula(int i);

private:
	// Estrutura usada para guardar uma coluna j e seu s(j)
	struct Elemento {
		int j, s;
		Elemento (int i_j, int i_s);
	};

	int n;
	int l;
	std::function< double(int,int,double) > A;
	std::vector<Elemento> E;
	std::vector<double> V;

	// Devolve a intersecção entre as colunas a e b onde a <= b
	virtual int Intersecta(int a, int b);
};
