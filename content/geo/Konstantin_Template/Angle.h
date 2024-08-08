/**
 * Description: Sorts points CCW starting from positive x-axis, does not handle (0, 0)
 * Usage: sort(pts.begin(), pts.end(), cmp_ang);
 */
#pragma once

#include "GeometryPrimitives.h"

const pt orig(0, 0);
bool cmp_ang(const pt& a, const pt& b) {
  bool aorig = cmp_lex_i(orig, a), borig = cmp_lex_i(orig, b);
  if (aorig ^ borig) return aorig; else return cp(a-orig, b-orig) > 0; }
