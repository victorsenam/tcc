/**
    Algoritmo SMAWK

    Encontra os índices de mínimos das linhas de uma matriz totalmente 
    monótona convexa nas linhas.

    Autor: Victor Sena Molero <victorsenam>
    Projeto: "Algoritmos em matrizes monótonas e Monge convexas"
    Disponível em: https://github.com/victorsenam/tcc/
**/
#ifndef TCC_SMAWK
#define TCC_SMAWK

#include <vector>
#include <list>
#include <functional>
#include <climits>

/**
    Remove colunas inúteis de uma matriz

    Recebe uma função que representa uma matriz A com n linhas e considera
    removidas todas as linhas que não são da forma kp com k inteiro e todas
    as colunas que não pertencem à lista col.

    Retorna uma nova lista res que contém apenas colunas úteis (que podem
    conter algum índice de mínimo de linha) da matriz recebida com tamanho 
    exatamente (n+p-1)/p.

    Assume:
    - Matriz (A,n,p,col) recebida é totalmente monótona convexa nas linhas.

    Garante:
    - Matriz (A,n,p,res) devolvida é totalmente monótona convexa nas linhas
    e tem índices de mínimos de linhas iguais às da matriz recebida.
**/
std::list<int> Reduce (std::function< int(int,int) > A, int n, int p, std::list<int> col);

/**
    Encontra os índices de mínimos das linhas de uma matriz

    Recebe uma função que representa uma matriz A com n linhas e considera
    removidas todas as linhas que não são da forma kp com k inteiro e todas
    as colunas que não pertencem à lista col.

    Preenche o vetor res com os valores dos índices de mínimos das linhas da
    matriz recebida nas posições apropriadas.
    
    Assume: 
    - Matriz (A,n,p,col) recebida é quadrada e totalmente monótona convexa
    nas linhas.
**/
void SMAWK (std::function< int(int,int) > A, int n, int p, const std::list<int> & col, std::vector <int> & res);

/**
    Encontra os índices de mínimos das linhas de uma matriz

    Recebe uma função que representa uma matriz A com n linhas e m colunas.
    
    Retorna o vetor dos índices de mínimos das linhas da matriz A.

    Assume:
    - Matriz (A,n,m) recebida é totalmente monótona convexa.
**/
std::vector<int> SMAWK (std::function< int(int,int) > A, int n, int m);

#endif
