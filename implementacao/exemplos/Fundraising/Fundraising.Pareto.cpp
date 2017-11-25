/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <map>
#include "../../algoritmos/Pareto.h"

int main () {
	int n;
	std::map<std::pair<long long,long long>,long long> mp;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		std::pair<long long,long long> p;
		long long d;
		scanf("%lld %lld %lld", &p.first, &p.second, &d);
		p.second = -p.second;
		mp[p] += d;
	}

	Pareto Fronteira;
	Fronteira.Insere(std::pair<double,double>(0,0));
	double res = 0;
	
	for (auto it : mp) {
		double cur = it.second + Fronteira.CalculaM(it.first.second+1);
		Fronteira.Insere(std::pair<double,double>(it.first.second,cur));
		res = std::max(res,cur);
	}

	printf("%lld\n", (long long) res);
}
