/**
 * Description: Returns the convex hull of p in ccw order. Assumes CH is not a line.
 * Status: tested SPOJ BSHEEP, UVA 11096
 * Time: O(n \log n)
*/
#pragma once

#include "GeometryPrimitives.h"
pol chull(pol p) {
  sort(p.begin(), p.end(), cmp_lex_i); int top=0, bot=1, n=p.size();
  pol ch(2*n); for (int i = 0, d = 1; i < n && i >= 0; i += d) {
    // If no duplicates, can change <= 0 to < 0 to keep redundant points
    while (top>bot && cp(ch[top-1]-ch[top-2], p[i]-ch[top-2])<=0) top--;
    ch[top++] = p[i]; if (i == n-1) d = -1, bot = top;
  } ch.resize(max(1, top-1)); return ch; }
