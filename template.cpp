#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
#define sq(a) ((a) * (a))

#define MOO(i, a, b) for (int i = a; i < b; i++)
#define M00(i, a) for (int i = 0; i < a; i++)
#define MOOd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define M00d(i, a) for (int i = (a) - 1; i >= 0; i--)

#define per(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define rep(i, a, b) for (int i = a; i < b; i++)

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define F0R(i, a) for (int i = 0; i < a; i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define R0F(i, a) for (int i = (a) - 1; i >= 0; i--)

#define FAST                                                                   \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);

#ifdef DEBUG_ENABLED
#define dbg(x) cerr << ">>> " << #x << " = " << x << endl;
#define _ << " _ " <<
#else
#define dbg(x) // Debugging is disabled, do nothing
#endif

#define int long long

template <class T> bool ckmin(T &a, T b) {
  bool B = a > b;
  a = min(a, b);
  return B;
}
template <class T> bool ckmax(T &a, T b) {
  bool B = a < b;
  a = max(a, b);
  return B;
}

typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld, ld> pld;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;

#define trav(a, x) for (auto &a : x)

const ld PI = acos(-1.0);
const ld EPS = 1e-7;
const int MOD = 1e9 + 7;

// Global Constants and Variables here

void solve() {}

int32_t main() {
  FAST mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
}
