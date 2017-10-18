#include "Pareto.h"

void Pareto::Insere (std::pair<double,double> x) {
	auto y = s.lower_bound(x);

	if (y != s.end() && y->second >= x.second)
		return;

	while (y != s.begin() && std::prev(y)->second <= x.second)
		s.erase(std::prev(y));
		
	s.insert(x);
}

double Pareto::CalculaM (double c) {
	auto y = s.lower_bound(std::pair<double,double>(c,-1./0.));
	if (y != s.end())
		return y->second;
	return -1./0.;
}
