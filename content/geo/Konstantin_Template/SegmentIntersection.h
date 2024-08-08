/**
 * Author: Jason?
 * Description: Returns true if segment a--b intersects c--d.
 */
#pragma once

#include "GeometryPrimitives.h"
// handles ALL cases, uncomment the 3 marked lines to exclude endpoints
bool seg_x_seg(pt a, pt b, pt c, pt d) {
  //if(eq(a, b) || eq(c, d)) return 0; // exclude endpoints
  ld sa=abs(b-a), sc=abs(d-c); sa=sa>EPS?1/sa:0; sc=sc>EPS?1/sc:0;
  int r1 = sgn(cp(b-a, c-a) * sa), r2 = sgn(cp(b-a, d-a) * sa);
  int r3 = sgn(cp(d-c, a-c) * sc), r4 = sgn(cp(d-c, b-c) * sc);
  if(!r1 && !r2 && !r3) { // collinear
    if(cmp_lex(b, a)) swap(a, b);
    if(cmp_lex(d, c)) swap(c, d);
    //return cmp_lex(a, d) && cmp_lex(c, b); // exclude endpoints
    return !cmp_lex(d, a) && !cmp_lex(b, c);
  } return r1*r2 <= 0 && r3*r4 <= 0; }//change to < to exclude endpoints
