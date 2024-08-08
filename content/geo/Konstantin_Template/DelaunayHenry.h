/**
 * Author: Henry Xia
 * Date: 2018
 * Description: Sketch Delaunay triangulation. No idea when this works.
 * returns the Delaunay Triangulation as triples of indices
 * Time: O(\text{very}~n^2)
 * Status: Tested WF2018G
 */
#pragma once

pt circumcenter(const pt& A, const pt& B, const pt& C) {
  ld a = norm(B-C), b = norm(C-A), c = norm(A-B);
  ld fa = a*(b+c-a), fb = b*(c+a-b), fc = c*(a+b-c);
  return (fa*A + fb*B + fc*C) / (fa+fb+fc);
}

struct Tuple { vector<int> v;
  Tuple() {}
  Tuple(int a, int b) { v={a,b}; sort(v.begin(), v.end()); }
  Tuple(int a, int b, int c) { v={a,b,c}; sort(v.begin(),v.end()); }
  bool operator == (const Tuple& t) const { return v == t.v; }
  int operator [] (int i) const { return v[i]; }
};

namespace std {
  template<> struct hash<Tuple> {
    size_t operator () (const Tuple& t) const {
      size_t h = 0;
      for (int i = 0; i < t.v.size(); i++)
        h ^= hash<int>()(t[i]<<(10*i)); //?????
      return h; } };
}

vector<Tuple> delaunay(vector<pt> p) {
  int n = p.size();
  p.push_back(pt(INF,INF));
  p.push_back(pt(INF,-INF));
  p.push_back(pt(-INF,0));

  unordered_map<Tuple,int> cnt;
  unordered_set<Tuple> cur;
  cur.insert(Tuple(n, n+1, n+2));
  for (int i = 0; i < n; i++) {
    vector<Tuple> border; // edge
    vector<Tuple> bad; // triangle
    cnt.clear();
    for (const Tuple& tri : cur) {
      pt cc = circumcenter(p[tri[0]], p[tri[1]], p[tri[2]]);
      if (abs(p[i]-cc) < abs(p[tri[0]]-cc)) {
        bad.push_back(tri);
        for (int j = 0; j < 3; j++) {
          cnt[Tuple(tri[j], tri[(j+1)%3])]++; } } }
    for (const Tuple& tri : bad) {
      for (int j = 0; j < 3; j++) {
        cur.erase(tri);
        if (cnt[Tuple(tri[j], tri[(j+1)%3])] == 1) {
          border.push_back(Tuple(tri[j], tri[(j+1)%3])); } } }
    for (const Tuple& e : border) { cur.insert(Tuple(i, e[0], e[1])); }
  }

  vector<Tuple> res;
  for (const Tuple& tri : cur) {
    if (tri[0] < n && tri[1] < n && tri[2] < n) res.push_back(tri);
  } return res;
}

// returns the voronoi vertices (UNTESTED) (for reference)
vector<pt> voronoi(const vector<pt>& p) {
  vector<Tuple> triangles = delaunay(p);
  vector<pt> res;
  for (const Tuple& t : triangles) {
    res.push_back(circumcenter(p[t[0]], p[t[1]], p[t[2]]));
  } return res;
}
