/**
    Fronteira de Pareto
	Seção 6

	Estrutura de dados fronteira de Pareto.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/

#ifndef TCC_Pareto
#define TCC_Pareto

#include <utility>
#include <set>

/**
	Representa a fronteira de pareto de um conjunto S.

	P é a árvore de busca binária balanceada que guarda os elementos da fronteira de S.
**/
class Pareto {
public:
	// Insere um novo elemento no conjunto
    void Insere(std::pair<double,double> x);
    // Calcula o valor de M(S,c)
    double CalculaM(double c);

private:
    std::set<std::pair<double,double> > P;
};

#endif
