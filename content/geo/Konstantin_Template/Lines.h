/**
 * Description: Line operations and distances.
 */

#include "GeometryPrimitives.h"

// Intersection of non-parallel lines a -> b, c -> d.
pt line_inter(const pt &a, const pt &b, const pt &c, const pt &d) {
  return a + cp(c - a, d - c) / cp(b - a, d - c) * (b - a); }

// Projection of (a -> p) to vector (a -> b), SIGNED - positive in front
ld proj_dist(const pt &a, const pt &b, const pt &p) {
  return dp(b - a, p - a) / abs(b - a); }

// SIGNED distance. Pt on the right of vector (a -> b) will be NEGATIVE.
ld lp_dist(const pt &a, const pt &b, const pt &p) {
  return cp(b - a, p - a) / abs(b - a); }

// Line segment (a, b) to pt p distance.
ld lsp_dist(const pt &a, const pt &b, const pt &p) {
  return dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0 ?
    abs(cp(b - a, p - a) / abs(b - a)) : min(abs(a - p), abs(b - p)); }

// Closest pt on line segment (a, b) to pt p.
pt lsp_closest(const pt &a, const pt &b, const pt &p) {
  if (dp(b - a, p - a) > 0 && dp(a - b, p - b) > 0)
    return abs(cp(b-a,p-a))<EPS ? p : line_inter(a,b,p,p+(a-b)*pt(0,1));
  return abs(a - p) < abs(b - p) ? a : b; }
