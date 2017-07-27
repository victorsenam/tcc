#include "Pareto.h"

struct Pareto {
    void insere (pair<double,double> x) {
        auto it = s.upper_bound(pair<double,double>(x,1./0.));

        while (it != s.begin() && prev(it).second <= x.second)
            s.erase(prev(it));

        if (calculaM(x.first) < x.second)
            s.insert(x);
    }

    double calculaM (double c) {
        auto it = s.lower_bound(pair<double,double>(c,-1./0.));
        if (it == s.end())
            return -1./0.;
        return it->second;
    }

    private:
    std::set<std::pair<double, double> > s;
};
