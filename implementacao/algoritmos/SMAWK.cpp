#include "SMAWK.h"
#include <iostream>
#include <cassert>

SMAWK::SMAWK (std::function< double(int, int) > A, int n, int m) {
	this->n = n;
	this->A = [A,m] (int i, int j) {
		if (j >= m) return 1./0.;
		else return A(i,j);
	};
	p = 1;
	for (int i = 0; i < m; i++)
		col.push_back(i);

	Reduce();
}

void SMAWK::RemoveOddRows () {
	p += p;
}

void SMAWK::Reduce () {
	int k = 0;
	std::list<int>::iterator it = col.begin();

    while (col.size() > unsigned(n + p - 1)/p) {
		assert(it != col.end() && std::next(it) != col.end());
        if (A(p*k, *it) <= A(p*k, *std::next(it))) {
			if (p*(k+1) >= n) {
                col.erase(std::next(it));
			} else {
				it = std::next(it);
				k++;
			}
		} else { 
			it = std::next(it);
            it = col.erase(std::prev(it));
			if (k != 0) {
				k--;
				it = std::prev(it);
			}
        }
    }
}

std::vector<int> SMAWK::FindRowMinima () {
	std::vector<int> R(n);
	FindRowMinima(R);
	return R;
}

void SMAWK::FindRowMinima (std::vector<int> & R) {
	if (p >= n) {
		assert(col.size() == 1u);
		R[0] = *(col.begin());
	} else {
		SMAWK B = (*this);
		B.RemoveOddRows();
		B.Reduce();
		B.FindRowMinima(R);
		
		std::list<int>::const_iterator it = col.begin();
		while (*it <= R[0])
			it = std::next(it);

		for (int i = p; i < n; i += p+p) {
			R[i] = R[i-p];

			while (it != col.end() && (i + p >= n || *it <= R[i+p])) {
				if (A(i,*it) < A(i,R[i]))
					R[i] = *it;
				it = std::next(it);
			}
		}

	}
}
