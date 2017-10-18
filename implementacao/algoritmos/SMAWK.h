/**
    Algoritmo SMAWK
	Seção 4

    Encontra os índices de mínimos das linhas de uma matriz totalmente monótona convexa nas linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/
#ifndef TCC_SMAWK
#define TCC_SMAWK

#include <vector>
#include <list>
#include <functional>

/**
	Representa uma matriz na qual pode ser aplicado o algoritmo SMAWK

	A matriz tem como entradas os valores dados pela função A. As linhas da matriz são os inteiros da forma k*p onde k é inteiro não negativo e k*p < n. As colunas da matriz são os inteiros presentes em col. A estrutura col deve estar ordenada crescentemente.  A matriz A deve ser totalmente monótona convexa nas linhas.
**/
class SMAWK {
public:
	// Constrói uma matriz dada pela função A com n linhas e m colunas
	SMAWK(std::function< double(int,int) > A, int n, int m);

	// Devolve um vetor com os índices dos mínimos das linhas da matriz
	std::vector<int> FindRowMinima();

private:
	std::function< double(int,int) > A;
	int n;
	std::list<int> col;
	int p;

	// Remove as linhas pares da matriz
	void RemoveOddRows();

	// Remove colunas inúteis da matriz
	void Reduce();

	// Preenche o vetor R com os índices dos mínimos das linhas da matriz
	void FindRowMinima(std::vector<int> & R);

};

#endif
