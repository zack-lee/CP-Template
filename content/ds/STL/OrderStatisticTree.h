/**
 * Description: A set (not multiset!) with support for finding the $n$'th
 * element, and finding the index of an element.
 * Time: O(\log N)
 * Source: KACTL
 * Verification: many
 */

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, 
	rb_tree_tag, tree_order_statistics_node_update>; 
// to get a map, change null_type

#define ook order_of_key
#define fbo find_by_order

void treeExample() {
	Tree<int> t, t2; t.insert(8);
	auto it = t.insert(10).f;
	assert(it == t.lb(9));
	assert(t.ook(10) == 1);
	assert(t.ook(11) == 2);
	assert(*t.fbo(0) == 8);
	t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}