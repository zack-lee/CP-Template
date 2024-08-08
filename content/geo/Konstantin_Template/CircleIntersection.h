/**
 * Description: Computes the pair of points at which two circles intersect. Returns number of intersections.
 * Status: tested UVa 453
 */
#pragma once

int cc_inter(pt p1, ld r1, pt p2, ld r2, pt &i1, pt &i2) {
  ld dq=norm(p1-p2), rq=r1*r1-r2*r2;
  pt c=(p1+p2)*0.5L + (p2-p1)*rq*0.5L/dq;
  ld dt=2.0*dq*(r1*r1+r2*r2)-dq*dq-rq*rq;
  if(dt < -EPS) return 0; else if(dt < EPS) { i1=i2=c; return 1; }
  dt=sqrt(dt)*0.5/dq; i1=c+(p2-p1)*pt(0,1)*dt; i2=c-(p2-p1)*pt(0,1)*dt;
  return 2; }
