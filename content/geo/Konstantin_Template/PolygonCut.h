/**
 * Description: Returns a vector with the vertices of a polygon with everything to the left of the line going from a to b cut away.
 * Status: Convex polygons tested UVa 10117,
 * Simple polygon tested KTH Challenge 2013 G (henryx: this confuses me because the remaining part could be disconnected)
 */
#pragma once

#include "GeometryPrimitives.h"
#include "Lines.h"
pol cut_polygon(const pol &v, const pt &a, const pt &b) { pol out;
  for(int i = v.size() - 1, j = 0; j < v.size(); i = j++) {
    if(cp(b-a, v[i]-a) < EPS) out.push_back(v[i]);
    if(sgn(cp(b-a, v[i]-a)) * sgn(cp(b-a, v[j]-a)) < 0) {
      pt p = line_inter(a, b, v[i], v[j]);
      if(!out.size() || abs(out.back() - p) > EPS) out.push_back(p); } }
  while(out.size() && abs(out[0] - out.back()) < EPS) out.pop_back();
  return out; }
