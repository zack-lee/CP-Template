/**
 * Description: Computes all faces, surface area, volume of the 3-dimension hull of a point set.
 *  All faces will point outwards. Code shifts points to near the origin, add base to unshift.
 * Time: O(n^2)
 * Status: tested SPOJ/CH3D, kattis/categorymanipulation,worminapple,threedprinter
 */
#pragma once

#include "Point3D.h"

namespace Hull3 { // change shift and mask values for >1024 verts
  const int S = 10; const int M = (1<<S) - 1;
  struct face{int a, b, c;};
  struct vert{p3d v; int i; operator p3d() const { return v; } };
  vector<face> faces; vector<vert> v; p3d base;
  ld dist(const face& f, const p3d& p) {
    return dot(cross(v[f.b]-v[f.a], v[f.c]-v[f.b]), p-v[f.a]); }
  ld area(const face& f) {
    return abs(cross(v[f.b]-v[f.a], v[f.c]-v[f.a])); }
  ld volume(const face& f) { p3d n=cross(v[f.b]-v[f.a], v[f.c]-v[f.b]);
    return area(f)*dot(n/abs(n), v[f.a])/6; }
  void convex_hull_clean_input(const vector<p3d>& _v) { int n=_v.size();
    v.resize(n); for(int i=0; i<n; i++) v[i] = {_v[i], i};
    shuffle(v.begin(), v.end(), rng);
    base = v[0]; for(int i=0; i<n; i++) v[i].v = v[i] - base;
    for(int i=1;i<n;i++) if(abs(v[i])>EPS) { swap(v[i],v[1]); break; }
    for(int i=2;i<n;i++) if(abs(cross(v[1], v[i])) > EPS) {
      swap(v[i], v[2]); break; }
    for(int i=3; i<n; i++) if(abs(dot(cross(v[1], v[2]), v[i])) > EPS) {
      swap(v[i], v[3]); break; } }
  void build(const vector<p3d>& _v) {
    convex_hull_clean_input(_v); int n = v.size();
    vector<face> f { {0, 1, 2}, {2, 1, 0} };
    for(int i=3; i<n; i++) { vector<face> nxt; set<int> edge;
      for(auto ff : f) { // remove the faces
        if(dist(ff, v[i]) > EPS) { // above
          edge.insert((ff.a << S) | ff.b);
          edge.insert((ff.b << S) | ff.c);
          edge.insert((ff.c << S) | ff.a);
        } else nxt.push_back(ff); }
      for(auto e : edge) { if(!edge.count(((e & M) << S) | (e >> S)))
        nxt.push_back(face{e >> S, e & M, i}); }
      f = nxt; } faces = f;
    //ld ar=0, vo=0; for (auto ff : f) ar += area(ff), vo += volume(ff);
  }
}
