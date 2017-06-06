/**
    Otimização da divisão e conquista

    Encontra os índices de mínimos das linhas de uma matriz monótona
    crescente nos mínimos das linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/
#ifndef TCC_DivConq
#define TCC_DivConq

#include <vector>
#include <functional>

/**
    Encontra os índices de mínimos das linhas de uma matriz

    Recebe uma função que representa uma matriz A e considera presentes
    apenas as linhas em [rs..rt] e as colunas em [cs..ct].

    Preenche o vetor res com os valores dos índices de mínimos das linhas
    da matriz recebida nas posições apropriadas.

    Assume:
    - Matriz (A,rs,rt,cs,ct) monótona crescente nos mínimos das linhas.
**/
void DivConq (std::function< double(int,int) > A, int rs, int rt, int cs, int ct, std::vector<int> & r);

/**
    Encontra os índices de mínimos das linhas de uma matriz

    Recebe uma função que representa uma matriz A com n linhas e m colunas.

    Retorna o vetor dos índices de mínimos das linhas da matriz A.

    Assume:
    - Matriz (A,n,m) recebida é totalmente monótona convexa.
**/
std::vector<int> DivConq (std::function< double(int,int) > A, int n, int m);

#endif
