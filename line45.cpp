#include "line45.hpp"
top::Line45::Line45(p_t left_bot, int size) :
  left_bot{left_bot}, size{size}
{}
top::p_t top::Line45::begin() const {
  return left_bot;
}
top::p_t top::Line45::next(p_t a) const {
  a.x++;
  a.y++;
  if (a.x - begin().x >= size) {
    return begin();
  }
  return a;
}