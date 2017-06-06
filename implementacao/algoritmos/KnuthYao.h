/**
    Otimização de Knuth-Yao

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
    Resolve uma recorrência de intervalos.

    Recebe uma função que representa uma matriz C com n linhas e colunas.

    Retorna a solução da recorrência de intervalos com matriz de custo C.

    Assume:
    - A recorrência de intervalos com matriz de custos C é Knuth-Yao 
    otimizável.
**/
std::vector<std::vector<double> > KnuthYao (std::function< double(int,int) > C, int n);

#endif
