/**
 * Description: Given set of lines, computes greatest $y$-coordinate for any $x$
 * Time: O(\log N)
 * Source: KACTL
   * https://codeforces.com/blog/entry/63823?#comment-477568
 * Verification: 
   * CSA Squared Ends not working :(
   * https://codeforces.com/contest/1083/problem/E
   * https://atcoder.jp/contests/arc066/tasks/arc066_d
 */

struct Line {
	mutable int k, m, p; // slope, y-intercept, last optimal x
	int eval (int x) { return k*x+m; }
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(int x) const { return p < x; }
};

struct LC : multiset<Line,less<>> { 
	// for doubles, use inf = 1/.0, div(a,b) = a/b
	const int inf = LLONG_MAX;
	int div(int a, int b) { return a/b-((a^b) < 0 && a%b); } // floored division
	int bet(const Line& x, const Line& y) { // last x such that first line is better
		if (x.k == y.k) return x.m >= y.m ? inf : -inf;
		return div(y.m-x.m,x.k-y.k);
	}
	bool isect(iterator x, iterator y) { // updates x->p, determines if y is unneeded
		if (y == end()) { x->p = inf; return 0; }
		x->p = bet(*x,*y); return x->p >= y->p;
	}
	void add(int k, int m) {
		auto z = insert({k,m,0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	int query(int x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k*x+l.m;
	}
};