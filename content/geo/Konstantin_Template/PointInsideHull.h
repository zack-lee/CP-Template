/**
 * Author: chilli
 * Date: 2019-05-17
 * License: CC0
 * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new
 * Description: Determine whether a point t lies inside a convex hull (CCW
 * order, with no colinear points). Returns true if point lies within
 * the hull. If strict is true, points on the boundary aren't included.
 * Usage:
 * Status: fuzz-tested
 * Time: O(\log N)
 */
#pragma once

#include "GeometryPrimitives.h"
#include "InsidePolygon.h"

bool in_hull(const pt& p, const vector<pt>& l, bool strict = true) {
	int a = 1, b = (int)l.size() - 1, r = !strict;
	if (l.size() < 3)
    return r &&
      (eq(p,l[0]) || eq(p,l.back()) || on_segment(l[0],l.back(),p));
	if (sgn(cp(l[a]-l[0], l[b]-l[0])) > 0) swap(a, b);
	if (sgn(cp(l[a]-l[0],p-l[0])) >= r || sgn(cp(l[b]-l[0],p-l[0])) <= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(sgn(cp(l[c]-l[0], p-l[0])) > 0 ? b : a) = c;
	}
	return sgn(cp(l[b]-l[a], p-l[a])) < r;
}
