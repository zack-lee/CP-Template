/**
 * Description: Convex hull of circles.
 * Status: tested on UVa
 */
#pragma once

#include "GeometryPrimitives.h"
#include "CircleTangent.h"

const ld far = 1e10; // can't be too big or precision error
pt center[MAXN]; ld radius[MAXN]; int V; // # of circles
// true if circle1 is in circle2
bool c_in_c(pt c1, ld r1, pt c2, ld r2) {
  ld d = abs(c1 - c2); return r1 - EPS <= r2 && d + r1 - EPS <= r2; }
// convex hull of circles
ld solve() { // find lowest point; and biggest circle
  pt lowest(far, far);
  // need 2nd point because we may touch the first circle TWICE
  int first = -1, second = -1;
  for (int i = 0; i < V; ++i) { pt low = center[i] - pt(0, radius[i]);
    if (cmp_lex_i(low, lowest)) { lowest = low; first = i; }
    else if (abs(low - lowest) < EPS &&
      c_in_c(center[first],radius[first],center[i],radius[i])) first=i;}
  ld perim = 0; pt left(-far, lowest.imag()), right(far, lowest.imag());
  pt A = left, B = lowest; int i = first;
  while (true) { // tangents are A-B C-D, B and C lie on the same circle
    pt C = A, D = B; int nxt = i; ld nxt_angle = 1e9;
    for (int j = 0; j < V; ++j) { if (i == j) continue;
      // check if inside current circle
      if(c_in_c(center[j], radius[j], center[i], radius[i])) continue;
      // bot-bot since we are doing counter clockwise
      // tangent.first lies on first circle etc.
      auto t=circle_tangent(center[i],radius[i],center[j],radius[j],1);
      ld angle=atan2(cp(B-A,t.second-t.first),dp(B-A,t.second-t.first));
      if (angle < -EPS) angle += PI * 2;
      if (angle + EPS < nxt_angle) { nxt_angle = angle; nxt = j;
        C = t.first; D = t.second; } }
    if (nxt == i) { perim += radius[i] * PI * 2; break; }
    if (i == first && second == -1) second = nxt;
    else if (i == first && second == nxt) { // done,calculate last angle
      perim += radius[i] * nxt_angle; break; }
    else perim += radius[i] * nxt_angle;
    perim += abs(C - D); A = C; B = D; i = nxt; } return perim; }
