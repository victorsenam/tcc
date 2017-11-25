/**
	Este código é uma parte do Trabalho de Conclusão do Bacharelado em Ciência da Computação de Victor Sena Molero pela Universidade de São Paulo. O Trabalho completo está presente em http://github.com/victorsenam/tcc e esta implementação é documentada no Capítulo "Exemplos Implementados".
**/

#include <cstdio>
#include <vector>
#include <algorithm>

int cmp (int a, int b) {
	return (a <= b) + (a == b);
}

int main () {
	int n;
	scanf("%d", &n);
	std::vector<std::pair<long long,long long> > v(n);
	std::vector<long long> d(n);
	std::vector<int> p(n);
	std::vector<long long> r(n);

	for (int i = 0; i < n; i++) {
		scanf("%lld %lld %lld", &v[i].first, &v[i].second, &d[i]);
		p[i] = i;
	}

	std::sort(p.begin(), p.end(), [v] (int i, int j) {
		return v[i] < v[j];
	});

	long long res = 0;
	for (int _i = 0; _i < n; _i++) {
		int i = p[_i];
		r[i] = 0;
		for (int _j = 0; _j < _i; _j++) {
			int j = p[_j];
			if (cmp(v[j].first,v[i].first) == cmp(v[j].second,v[i].second))
				r[i] = std::max(r[i], r[j]);
		}
		r[i] += d[i];

		res = std::max(res, r[i]);
	}

	printf("%lld\n", res);
}
