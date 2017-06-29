#include <iostream>
#include <deque>

/*
    Imprime na saída padrão o vetor $E[1 \tdots n]$ definido por
    $$ E[j] = \min_{0 \leq i < j}\{ E[i] + w(i,j) \} $$
    onde $E[0] = 0$.
*/

/* determinando a função w */
const int n = 5;
const int a[] = {100, 20, 10, 5, 2, 1};
const int b[] = { 9,  1, 7, 2, 3, 5};
const int x[] = {1, 2, 3, 4, 5, 6};

int w (int i, int j) {
    return a[i]*x[j] + b[i];
}

/* vetor resposta */
int E[n+1];

/* classe para manipular uma linha da estrutura de dados */
struct line {
    int i; // linha sendo representada
    int j; // coluna a partir da qual i é ótima

    line (int a, int b) : i(a), j(b) {}
};

/* calcula B[i][j] assumindo que E[i] é conhecido */
int B (int i, int j)
{ return E[i] + w(i,j); }

int main () {

    // deque é uma estrutura de dados capaz 
    std::deque<line> v;
    v.push_back(line(0,0));
    
    for (int j = 1; j <= n; j++) {
        // remove o primeiro intervalo até alcançar um que cubra a região atual
        while (v.size() > 1 && v[1].j <= j)
            v.pop_front();

        // calcula E[j]
        E[j] = B(v.front().i,j); 
        std::cout << E[j] << std::endl;

        line cur(j, n+1);

        // remove todos os intervalos do final que perdem sempre pra j
        while (!v.empty() && B(cur.i,v.back().j) < B(v.back().i,v.back().j)) {
            cur.j = v.back().j;
            v.pop_back();
        }
        
        if (!v.empty()) {
            // descobre menor ponto onde j ganha do topo da estrutura
            int i = v.back().i;
            int lo = v.back().j;
            int hi = n+1;

            while (lo < hi) {
                int mid = lo+(hi-lo)/2;
                if (B(cur.i,mid) < B(i,mid))
                    hi = mid;
                else
                    lo = mid+1;
            }

            cur.j = lo;
        }
        
        if (cur.j <= n)
            v.push_back(cur);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++)
            std::cout << "--- ";
        for (int j = i+1; j <= n; j++)
            std::cout << B(i,j) << " ";
        std::cout << std::endl;
    }

}
