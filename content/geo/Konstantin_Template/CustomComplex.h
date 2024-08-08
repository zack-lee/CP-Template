/**
 * Description: Fast handwritten complex number class; about
 * $4 \times$ faster than std::complex.
 * Status: tested PacNW2013J Phuket2016G CHICAGO 2012H
 */
#pragma once

namespace CustomComplex {
template<class T> struct cplx {
  T x, y; cplx(T nx=0, T ny=0): x(nx), y(ny) {}
  cplx operator+(const cplx &c) const { return {x+c.x, y+c.y}; }
	cplx operator-(const cplx &c) const { return {x-c.x, y-c.y}; }
  cplx operator*(const cplx &c) const {
    return {x*c.x-y*c.y, x*c.y+y*c.x}; }
  cplx& operator*=(const cplx &c) {
    return *this={x*c.x-y*c.y, x*c.y+y*c.x}; }
  // Only supports right scalar multiplication like p*c
  template<class U> cplx operator*(const U &c) const {return {x*c,y*c};}
  template<class U> cplx operator/(const U &c) const {return {x/c,y/c};}
  bool operator<(const cplx& o) const {return tie(x,y)<tie(o.x,o.y);} };
#define polar(r,a)  (pt){r*cos(a),r*sin(a)}
using pt = cplx<ld>;
using pol = vector<pt>;
/// for left mult. c*p
pt operator*(ld c, const pt p) { return {p.x*c,p.y*c};}
/// useful for debugging
ostream& operator<<(ostream &o,const pt &p) {
  return o<<"("<<p.x<<","<<p.y<<")"; }
ld cp(const pt& a, const pt& b) { return a.x*b.y - b.x*a.y; }
ld dp(const pt& a, const pt& b) { return a.x*b.x + a.y*b.y; }
inline ld norm(const pt& a) { return a.x*a.x + a.y*a.y; }
inline ld abs(const pt &a) {return sqrt(a.x*a.x + a.y*a.y);}
inline ld arg(const pt &a) {return atan2(a.y,a.x);}
ld ang(const pt &a, const pt &b, const pt &c) {
	return atan2(cp(a-b,b-c),dp(a-b,b-c)); }
inline bool cmp_lex(const pt& a, const pt& b) {
  return a.x<b.x-EPS||(a.x<b.x+EPS&&a.y<b.y-EPS);}
inline bool cmp_lex_i(const pt& a, const pt& b) {
  return a.y<b.y-EPS||(a.y<b.y+EPS&&a.x<b.x-EPS);}
}
