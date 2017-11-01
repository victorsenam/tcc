#include "EnvelopeConvexo.h"

EnvelopeConvexo::EnvelopeConvexo (std::function< double(int,int,double) > A, int n) {
	::A = A;
	::n = n;
	V.resize(n);
}

int EnvelopeConvexo::Calcula () {
	return E.back();
}

void EnvelopeConvexo::Remove () {
	while (!E.empty() && s(std::prev(E.end())) == n-1)
		E.pop_back();
	n--;
}

void EnvelopeConvexo::Insere (int j) {
	if (E.empty() || A(1,j) <= A(1,E.front())) {
		while (!E.empty() && A(t(E.begin()),j) <= A(t(E.begin()),E.front()))
			E.pop_front();
		E.push_front(j);
	}
}

int EnvelopeConvexo::Intersecta (int a, int b) {
	int l = 0, r = n - 1;
	while (l < r) {
		int m = (l+r)/2;
		if (A(m,a) <= A(m,b))
			l = m;
		else
			r = m - 1;
	}
	return l;
}

int EnvelopeConvexo::s (std::deque<int>::iterator it) {
	if (it == E.begin())
		return 0;
	return Intersecta(*std::prev(it), *it);
}

int EnvelopeConvexo::t (std::deque<int>::iterator it) {
	if (std::next(it) == E.end())
		return n-1;
	return Intersecta(*it, *std::next(it));
}
