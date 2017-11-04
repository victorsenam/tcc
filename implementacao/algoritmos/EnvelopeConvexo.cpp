#include "EnvelopeConvexo.h"

EnvelopeConvexo::EnvelopeConvexo (std::function< double(int,int) > A, int n) {
	this->A = A;
	this->n = n;
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
	if (E.empty() || A(0,j) <= A(0,E.front())) {
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
			l = m + 1;
		else
			r = m;
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
