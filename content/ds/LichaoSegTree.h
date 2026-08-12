/**
 * Description: LiChao Segment Tree
 * Source: atatomir, misc
 * Verification: CSA Squared Ends
 */

const int INF = 1e18;

struct Line {
	int k,m;
	Line(int _k, int _m) { k = _k, m = _m; }
	Line() : Line(0,-INF) { }
	int get(int x) { return k*x+m; }
	bool majorize(Line X, int L, int R) { 
		return get(L) >= X.get(L) && get(R) >= X.get(R); 
	}
};

struct lc {
	lc* c[2];
	Line S;
	
	lc() {
		c[0] = c[1] = NULL;
		S = Line();
	}
	
	void rm() {
		if (c[0]) c[0]->rm();
		if (c[1]) c[1]->rm();
		delete this;
	}
	
	void mc(int i) {
		if (!c[i]) c[i] = new lc();
	}
	
	int query(int X, int L, int R) {
		int ans = S.get(X), M = (L+R)/2;
		if (X <= M) return max(ans, c[0] ? c[0]->query(X,L,M): -INF);
		return max(ans, c[1] ? c[1]->query(X,M+1,R): -INF);
	}
	
	void modify(Line X, int L, int R) {
		if (X.majorize(S,L,R)) swap(X,S);
		if (S.majorize(X,L,R)) return;
		if (S.get(L) < X.get(L)) swap(X,S);
		
		int M = (L+R)/2;
		if (X.get(M) >= S.get(M)) swap(X,S), mc(0), c[0]->modify(X,L,M);
		else mc(1), c[1]->modify(X,M+1,R);
	}
	
	void upd(Line X, int lo, int hi, int L, int R) { // untested
		if (R < hi || L < lo) return;
		if (lo <= L && R <= hi) { modify(X,L,R); return; }
		int M = (L+R)/2;
		mc(0), c[0]->upd(X,lo,hi,L,M);
		mc(1), c[1]->upd(X,lo,hi,M+1,R);
	}
};