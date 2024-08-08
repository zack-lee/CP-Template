/**
 * Description: Area of a polygon (convex or concave). Always non-negative. For signed area, remove \texttt{abs}.
 */
#pragma once

#include "GeometryPrimitives.h"

ld area(const pol &v) { ld s = 0; int n = v.size();
  for(int i = n-1, j = 0; j < n; i = j++) s += cp(v[i], v[j]);
  return abs(s)/2;}
