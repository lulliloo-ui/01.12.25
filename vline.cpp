#include "vline.hpp"
top::Vline::Vline(p_t y, int size) :
  ybot{y}, size{size}
{}
top::p_t top::Vline::begin() const {
  return ybot;
}
top::p_t top::Vline::next(p_t a) const {
  a.y++;
  if (a.y - begin().y >= size) {
    return begin();
  }
  return a;
}
