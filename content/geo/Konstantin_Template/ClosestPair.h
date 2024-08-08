/**
 * Description: Finds the closest pair of points. Assumes v.size() >= 2.
 * Time: O(n \log n)
 * Status: Tested UVa 10245, 11378
 */
#pragma once

#include "GeometryPrimitives.h"
pair<pt, pt> closest_pair(vector<pt> v) {
  sort(v.begin(), v.end(), cmp_lex);
  ld best = 1e99; auto low = 0u; pair<pt, pt> bestpair;
  set<pt, bool(*)(const pt&,const pt&)> help(cmp_lex_i);
  for(auto i = 0u; i < v.size(); i++) {
    while(low < i && (v[i] - v[low]).real() > best)help.erase(v[low++]);
    for(auto it = help.lower_bound(v[i] - pt(1e99, best));
          it != help.end() && (*it - v[i]).imag() < best; it++)
      if (abs(*it - v[i]) < best)
        best = abs(*it - v[i]), bestpair = make_pair(*it, v[i]);
    help.insert(v[i]); }
  return bestpair; }
