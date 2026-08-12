/**
 * Description: Euclidean Algorithm
 * Source: KACTL
 */

pi euclid(int a, int b) { // returns {x,y} such that a*x+b*y=gcd(a,b)
	if (!b) return {1,0};
	pi p = euclid(b,a%b);
	return {p.s,p.f-a/b*p.s};
}
int invGeneral(int a, int b) {
	pi p = euclid(a,b); assert(p.f*a+p.s*b == 1);
	return p.f+(p.f<0)*b;
}