#include "Pareto.h"

void Pareto::Insere (std::pair<double,double> x) {
	auto y = P.lower_bound(x);

	if (y != P.end() && y->second >= x.second)
		return;

	while (y != P.begin() && std::prev(y)->second <= x.second)
		P.erase(std::prev(y));
		
	P.insert(x);
}

double Pareto::CalculaM (double c) {
	auto y = P.lower_bound(std::pair<double,double>(c,-1./0.));
	if (y != P.end())
		return y->second;
	return -1./0.;
}
