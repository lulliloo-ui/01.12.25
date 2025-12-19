#include "dot.hpp"
top::Dot::Dot(int x, int y) :
  Idraw(),
  o{x, y}
{}
top::Dot::Dot(p_t dd) : Idraw(), o{dd} 
{}
top::p_t top::Dot::begin() const{
  return o;
}
top::p_t top::Dot::next(p_t) const {
  return begin();
}