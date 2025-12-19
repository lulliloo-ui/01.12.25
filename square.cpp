#include "square.hpp"
top::Square::Square(p_t left_bot, int length) :
  left_bot{left_bot}, length{length}
{}
top::p_t top::Square::begin() const {
  return left_bot;
}
top::p_t top::Square::next(p_t a) const {
  if (a.x == begin().x && a.y < begin().y + length - 1) {
    a.y++;
    return a;
  }
  if (a.y == begin().y + length - 1 && a.x < begin().x + length - 1) {
    a.x++;
    return a;
  }
  if (a.x == begin().x + length - 1 && a.y > begin().y) {
    a.y--;
    return a;
  }
  if (a.y == begin().y && a.x > begin().x) {
    a.x--;
    return a;
  }
  return begin();
}
