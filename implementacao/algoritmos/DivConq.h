/**
    Otimização da divisão e conquista
	Seção 3

    Encontra os índices de mínimos das linhas de uma matriz monótona crescente nos mínimos das linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/
#ifndef TCC_DivConq
#define TCC_DivConq

#include <vector>
#include <functional>

/**
	Representa uma matriz na qual pode ser aplicado o algoritmo DivConq
	
	A matriz tem como entradas os valores dados pela função A. As linhas da matriz são os inteiros de 0 até n-1. As colunas da matriz são os inteiros de 0 até m-1. A matriz A deve ser monótona crescente nos mínimos das linhas.
**/

class DivConq {
public:
	// Constrói uma matriz dada pela função A com n linhas e m colunas
	DivConq(std::function< double(int,int) > A, int n, int m);

	// Devolve um vetor com os índices dos mínimos das linhas da matriz
	std::vector<int> FindRowMinima();

private:
	std::function< double(int,int) > A;
	int n;
	int m;

	// Preenche o vetor R com os índices dos mínimos das linhas da submatriz com linhas [rs..rt] e colunas [cs..ct]
	void FindRowMinima(int rs, int rt, int cs, int ct, vector<int> & R);
};
