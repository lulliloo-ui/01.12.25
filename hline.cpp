#include "hline.hpp"
top::Hline::Hline(p_t x, int size) :
  xleft{x}, size{size}
{}
top::p_t top::Hline::begin() const {
  return xleft;
}
top::p_t top::Hline::next(p_t a) const {
  a.x++;
  if (a.x - begin().x >= size) {
    return begin();
  }
  return a;
}