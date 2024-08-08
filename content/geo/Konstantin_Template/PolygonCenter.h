/**
 * Description: Returns the center of mass for a polygon (orientation does not matter).
 * Time: O(n)
 */
#pragma once

#include "GeometryPrimitives.h"

pt centroid(const pol &v) {
  pt res; ld A = 0; int n = v.size();
  for(int i = n-1, j = 0; j < n; i = j++)
    A+=cp(v[i],v[j]), res+=(v[i]+v[j])*cp(v[i],v[j]);
  return abs(A) < EPS ? res : res/3.L/A; }
