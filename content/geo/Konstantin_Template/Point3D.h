/**
 * Description: General 3d geometry.
 */
#pragma once

struct p3d{ ld x,y,z;
  friend ostream& operator<< (ostream& os, const p3d& p) {
  return os << "(" << p.x << "," << p.y << "," << p.z << ")"; } };
ld abs(const p3d &v){ return sqrt(v.x*v.x + v.y*v.y + v.z*v.z); }
p3d operator+(const p3d& a, const p3d& b) {
  return {a.x+b.x,a.y+b.y,a.z+b.z}; }
p3d operator-(const p3d& a, const p3d& b) {
  return {a.x-b.x,a.y-b.y,a.z-b.z}; }
p3d operator*(const ld &s, const p3d &v){ return {s*v.x,s*v.y,s*v.z}; }
p3d operator/(const p3d&v, const ld &s){ return {v.x/s, v.y/s, v.z/s}; }
inline ld dot(const p3d &a, const p3d &b){
  return a.x*b.x + a.y*b.y + a.z*b.z; }
inline p3d cross(const p3d &a, const p3d &b){
  return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x}; }
// Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
ld phi(const p3d& a) { return atan2(a.y, a.x); }
// Zenith angle (latitude) to the z-axis in interval [0, pi]
ld theta(const p3d& a) { return atan2(sqrt(a.x*a.x+a.y*a.y), a.z); }
inline ld dist(const p3d &s, const p3d &p) {
  return (p.x-s.x)*(p.x-s.x)+(p.y-s.y)*(p.y-s.y)+(p.z-s.z)*(p.z-s.z); }
// plane/line intersection. p - pt on plane, n - normal, a1 -> a2 : line
p3d pl_inter(const p3d &p, const p3d &n, const p3d &a1, const p3d &a2) {
  return a1 + dot(p - a1, n)/dot(n, a2 - a1)*(a2 - a1); }
// CCW rotation about arbitrary axis; tested pacnw2009D but pray anyway
p3d rotate(const p3d& p/*pt*/, const p3d& u/*axis*/, const ld& angle) {
  ld c = cos(angle), s = sin(angle), t = 1 - cos(angle);  return {
    p.x*(t*u.x*u.x + c)+p.y*(t*u.x*u.y - s*u.z)+p.z*(t*u.x*u.z + s*u.y),
    p.x*(t*u.x*u.y + s*u.z)+p.y*(t*u.y*u.y + c)+p.z*(t*u.y*u.z - s*u.x),
    p.x*(t*u.x*u.z - s*u.y)+p.y*(t*u.y*u.z + s*u.x)+p.z*(t*u.z*u.z + c)
  }; } // hash: 3f78e3
