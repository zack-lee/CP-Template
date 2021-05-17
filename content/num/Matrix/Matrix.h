/**
 * Description: 2D matrix operations
 * Source: KACTL
 * Verification: https://dmoj.ca/problem/si17c1p5, SPOJ MIFF
 */

template<class T> struct Mat {
	int r,c;
	vector<vector<T>> d;
	Mat(int _r, int _c) : r(_r), c(_c) { d.assign(r,vector<T>(c)); }
	Mat() : Mat(0,0) {} 
	Mat(const vector<vector<T>>& _d) : r(sz(_d)), c(sz(_d[0])) { d = _d; }
	friend void pr(const Mat& m) { pr(m.d); }
	
	Mat& operator+=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] += m.d[i][j];
		return *this;
	}
	Mat& operator-=(const Mat& m) {
		assert(r == m.r && c == m.c);
		F0R(i,r) F0R(j,c) d[i][j] -= m.d[i][j];
		return *this;
	}
	Mat operator*(const Mat& m) {
		assert(c == m.r); Mat x(r,m.c);
		F0R(i,r) F0R(j,c) F0R(k,m.c) x.d[i][k] += d[i][j]*m.d[j][k];
		return x;
	}
	
	Mat operator+(const Mat& m) { return Mat(*this)+=m; }
	Mat operator-(const Mat& m) { return Mat(*this)-=m; }
	Mat& operator*=(const Mat& m) { return *this = (*this)*m; }

	friend Mat pow(Mat m, ll p) {
		assert(m.r == m.c);
		Mat r(m.r,m.c);
		F0R(i,m.r) r.d[i][i] = 1;
		for (; p; p /= 2, m *= m) if (p&1) r *= m;
		return r;
	}
};