#include "SMAWK.h"

SMAWK::SMAWK (std::function< double(int, int) A, int n, int m) {
	::A = A;
	::n = n;
	p = 1;
	for (int i = 0; i < m; i++)
		col.push_back(i);
}

void SMAWK::RemoveEvenRows () {
	p += p;
}

void SMAWK::Reduce () {
	int k = 0;
	std::list<int>::iterator it = col.begin();

    while (col.size() > unsigned(n + p - 1)/p) {
        if (A(p*k, *it) > A(p*k, *std::next(it))) {
			it = std::next(it);
            it = col.erase(std::prev(it));
			if (k != 1) {
				k--;
				it = std::prev(it);
			}
        } else {
            if (p*(k+1) >= n) {
                col.erase(std::next(it));
            } else {
                it = std::next(it);
                k++;
            }
        }
    }
}

vector<int> SMAWK::FindRowMinima () {
	vector<int> R(n);
	FindRowMinima(R);
	return R;
}

void SMAWK::FindRowMinima (vector<int> & R) {
	if (p >= n) {
		R[0] = *(col.begin());
	} else {
		SMAWK B = (*this);
		B.RemoveEvenRows();
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
