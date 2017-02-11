/* Gerador de Monge Arrays baseados em soma acumulada
 * As matrizes geradas satisfazem a condição de Monge tanto no sentido côncavo quanto no convexo, ou seja,
 * para todo i,i',j' e j onde i < i' e j' < j, temos
 * w(i,j') + w(i',j) = w(i,j) + w(i',j')
 *
 * como esperado, isso faz com que os testes sejam fracos, já que o índice de máximo é
 * igual para todas as linhas da matriz
 */
#include <vector>
#include <iostream>

int main () {
    int n;
    std::vector<int> v, s;

    std::cin >> n;
    v.resize(n);
    s.resize(n);

    s[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        s[i] = s[i-!!i] + v[i];
    }

    std::cout << n << " " << n << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << s[j] - s[i] << " ";
        std::cout << std::endl;
    }
}
