#include "EnvelopeConvexoLinearLinear.h"

EnvelopeConvexoLinear::EnvelopeConvexoLinear (std::vector<double> alpha, std::vector<double> beta, int n) {
	::alpha = alpha;
	::beta = beta;
	::n = n;
	A = [&::alpha, &::beta] (int i, int j) {
		return alpha[j]*i + beta[j];
	};
}

EnvelopeConvexoLinear::Intersecta (int a, int b) {
	return floor((beta[a] - beta[b])/(alpha[b] - alpha[a]));
}
