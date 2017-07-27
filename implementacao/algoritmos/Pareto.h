/**
    Fronteira de Pareto
**/

#ifndef TCC_Pareto
#define TCC_Pareto

#include <utility>
#include <set>

struct Pareto {
    // insere um novo elemento
    void insere (pair<double, double> x);
    // calcula o valor de M(S,c) onde S são os elementos em s
    double calculaM (double c);

    private:
    // árvore de busca binária
    std::set<std::pair<double, double> > s;
};

#endif
