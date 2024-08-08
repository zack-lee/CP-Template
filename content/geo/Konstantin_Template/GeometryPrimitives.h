/**
 * Description: Geometry primitives.
 */
#pragma once
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef complex<ld> pt;
const ld EPS = 1e-9;

ld cp(const pt& a, const pt& b) { return imag(conj(a)*b); }
ld dp(const pt& a, const pt& b) { return real(conj(a)*b); }
// dist(const pt& a, const pt& b) ==> abs(a-b)
bool eq(const pt &a, const pt &b) { return abs(a-b) < EPS; }
int sgn(const ld& x) { return abs(x) < EPS ? 0 : x < 0 ? -1 : 1; }
bool cmp_lex(const pt& a, const pt& b) {
  return a.real()<b.real()-EPS
    ||  (a.real()<=b.real()+EPS && a.imag()<b.imag()-EPS); }

// REMOVE EPS I THINK FOR CONVEX HULL
inline bool cmp_lex_i(const pt& a, const pt& b) {
  return a.imag()<b.imag()-EPS
    ||  (a.imag()<=b.imag()+EPS && a.real()<b.real()-EPS); }
