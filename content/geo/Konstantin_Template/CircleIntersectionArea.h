/**
 * Description: returns area of intersection of 2 circles.
 * Status: untested
 */

#pragma once

ld cc_area(pt p1, ld r1, pt p2, ld r2) {
  if(r2 < r1) swap(p1, p2), swap(r1, r2);
  ld d = abs(p2 - p1); if (d + r1 < r2 + EPS) return r1*r1*PI;
  if (d >= r1 + r2) return 0;
  ld dA = (d*d + r1*r1 - r2*r2)/d/2, dB = d-dA;
  return r1*r1*acos(dA/r1) - dA*sqrt(r1*r1-dA*dA)
       + r2*r2*acos(dB/r2) - dB*sqrt(r2*r2-dB*dB); }
