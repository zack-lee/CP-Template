/**
 * Description: Returns tangent line between two circles. Also works for points. CAUTION: INTERSECTION IS BAD
 * Status: tested Chicago2012-H
 * Usage: k=0 top-top, k=1 bot-bot, k=2 top-bot, k=3 bot-top. 
 */

#pragma once

pair<pt, pt> circle_tangent(ld r1, ld r2, ld d, int k) { // use below fn
  ld dr = (k & 2) ? (-r1-r2) : (r2-r1); ld t = asin(dr / d);
  pt p1=polar(r1, PI/2+t), p2=polar(r2, PI/2+t); if(k&2) p2*=-1;
  p2+=pt(d,0);
  if(k&1){ p1=pt(p1.real(),-p1.imag()); p2=pt(p2.real(),-p2.imag()); }
  return make_pair(p1, p2); }
pair<pt, pt> circle_tangent(pt p1, ld r1, pt p2, ld r2, int k) {
  // translate/rotate so c1 at (0,0), c2 at x-axis
  pt d = p2-p1; auto p = circle_tangent(r1,r2,abs(d),k); d /= abs(d);
  p.first *= d; p.second *= d; p.first += p1; p.second += p1; return p;}
