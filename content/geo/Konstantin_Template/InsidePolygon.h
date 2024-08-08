/**
 * Description: Returns true if p is inside polygon v. Setting \texttt{strict} to true excludes boundary.
 */
#pragma once

#include "GeometryPrimitives.h"
// Does NOT include points on the ends of the segment.
inline bool on_segment(const pt &a, const pt &b, const pt &p) {
  return abs(cp(b-a, p-a)) / abs(a-b) < EPS &&
    dp(b-a, p-a)>0 && dp(a-b, p-b)>0; }

// Checks if p lies on the boundary of a polygon v.
inline bool on_boundary(const pol &v, const pt &p) {
  bool res = 0; for(int i=v.size()-1, j=0; j<v.size(); i=j++) {
    res |= on_segment(v[i], v[j], p) || abs(p-v[i]) < EPS; }
  return res; }

// orientation does not matter !!!
bool pt_in_polygon(const pt &p, const pol &v, bool strict=false) {
  if (on_boundary(v,p)) return !strict;
  ld res = 0; for(int i = v.size() - 1, j = 0; j < v.size(); i = j++) {
    res += atan2(cp(v[i] - p, v[j] - p), dp(v[i] - p, v[j] - p)); }
  return abs(res) > 1; } // will be either 2*PI or 0
