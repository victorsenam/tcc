#include "EnvelopeConcavo.h"

EnvelopeConcavo::EnvelopeConcavo (std::function< double(int,int) > A, int n) {
	this->A = A;
	this->n = n;
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
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int EnvelopeConcavo::s (std::deque<int>::iterator it) {
	if (std::next(it) == E.end())
		return 0;
	return Intersecta(*std::next(it), *it);
}

int EnvelopeConcavo::t (std::deque<int>::iterator it) {
	if (it == E.begin())
		return 0;
	return Intersecta(*it, *std::prev(it));
}
