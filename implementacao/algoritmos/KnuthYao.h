/**
    Otimização de Knuth-Yao
	Seção 5

    Resolve uma recorrência de intervalos Knuth-Yao otimizável.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/
#ifndef TCC_KnuthYao
#define TCC_KnuthYao

#include <vector>
#include <functional>

/**
	Representa uma recorrência de intervalos

 	A matriz de custos é representada pela matriz C. As linhas desta matriz são os inteiros de 0 até n-1. A recorrência de intervalos com matriz de custo C deve ser Knuth-Yao otimizável.
**/

class KnuthYao {
public:
	// Contrói a recorrência de intervalos com matriz de custo C com n linhas
	KnuthYao(std::function< double(int,int) > C, int n);

	// Devolve a solução da recorrência de intervalos
	std::vector<std::vector<double> > Solve();

private:
	std::function< double(int,int) > C;
	int n;
};

#endif
