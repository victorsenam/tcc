#include "EnvelopeConvexoLinear.h"

EnvelopeConvexoLinear::EnvelopeConvexoLinear (std::vector<long long> & alpha, std::vector<long long> & beta, int n) : alpha(alpha), beta(beta), EnvelopeConvexo([this] (int i, int j) {
	return this->alpha[j]*i + this->beta[j];
}, n) {}

int EnvelopeConvexoLinear::Intersecta (int a, int b) {
	int l = (beta[a] - beta[b] + alpha[b] - alpha[a] - 1)/(alpha[b] - alpha[a]);
	if (l < 0) l = 0;
	else if (l > n - 1) l = n - 1;
	return l;
}
