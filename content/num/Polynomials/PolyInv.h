/**
 * Description: ?
 * Time: ?
 * Source: CF, http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
 * Verification: https://codeforces.com/contest/438/problem/E
 */

#include "FFT.h"

template<class T> vector<T> inv(vector<T> v, int p) { // compute inverse of v mod x^p, where v[0] = 1 
	v.resize(p);  vector<T> a = {T(1)/v[0]};
	for (int i = 1; i < p; i *= 2) {
		if (2*i > p) v.resize(2*i);
		auto l = vector<T>(begin(v),begin(v)+i), r = vector<T>(begin(v)+i,begin(v)+2*i);
		auto c = mult(a,l); c = vector<T>(begin(c)+i,end(c));
		auto b = mult(a*T(-1),mult(a,r)+c); b.resize(i);
		a.insert(end(a),all(b));
	}
	a.resize(p); return a;
}