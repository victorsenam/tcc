/* Gerador de Monge Arrays baseados em soma acumulada
 * As matrizes geradas satisfazem a condição de Monge no sentido convexo, ou seja,
 * para todo i,i',j' e j onde i < i' e j' < j, temos
 * w(i,j') + w(i',j) <= w(i,j) + w(i',j')
 * 
 * Isso já gera testes um pouco mais razoáveis do que o monge-sum
 */
#include <vector>
#include <iostream>

int main () {
    int n;
    std::vector<int> v, s;

    std::cin >> n;
    v.resize(n);
    s.resize(n+1);

    s[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        s[i+1] = s[i] + v[i];
    }

    std::cout << n << " " << n << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i)
                std::cout << s[j+1] - s[i] << " ";
            else
                std::cout << -1000 << " ";
        }
        std::cout << std::endl;
    }
}
