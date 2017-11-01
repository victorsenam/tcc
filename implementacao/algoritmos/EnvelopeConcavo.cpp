#include "EnvelopeConcavo.h"

EnvelopeConcavo::EnvelopeConcavo (std::function< double(int,int,double) > A, int n) {
	::A = A;
	::n = n;
	V.resize(n);
}

int EnvelopeConcavo::Calcula () {
	return E.front();
}

void EnvelopeConcavo::Remove () {
	while (!E.empty() && s(E.begin()) == n-1)
		E.pop_front();
	n--;
}

void EnvelopeConcavo::Insere (int j) {
	if (E.empty() || A(n-1,j) <= A(n-1,E.front())) {
		while (!E.empty() && A(s(E.begin()),j) <= A(s(E.begin()),E.front()))
			E.pop_front();
		E.push_front(j);
	}
}

int EnvelopeConcavo::Intersecta (int a, int b) {
	int l = 0, r = n - 1;
	while (l < r) {
		int m = (l+r)/2;
		if (A(m,a) < A(m,b))
			l = m;
		else
			r = m - 1;
	}
	return l;
}

int EnvelopeConcavo::s (std::deque<int>::iterator it) {
	if (it == E.begin())
		return 0;
	return Intersecta(*it, *std::prev(it));
}

int EnvelopeConcavo::t (std::deque<int>::iterator it) {
	if (std::next(it) == E.end())
		return n-1;
	return Intersecta(*std::next(it), *it);
}
