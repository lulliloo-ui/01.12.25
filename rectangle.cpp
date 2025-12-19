#include "rectangle.hpp"
top::Rectangle::Rectangle(p_t left_bot, int length_a, int length_b) :
  left_bot{left_bot}, length_a{length_a}, length_b{length_b}
{}
top::p_t top::Rectangle::begin() const {
  return left_bot;
}
top::p_t top::Rectangle::next(p_t a) const {
  if (a.x == begin().x && a.y < begin().y + length_b - 1) {
    a.y++;
    return a;
  }
  if (a.y == begin().y + length_b - 1 && a.x < begin().x + length_a - 1) {
    a.x++;
    return a;
  }
  if (a.x == begin().x + length_a - 1 && a.y > begin().y) {
    a.y--;
    return a;
  }
  if (a.y == begin().y && a.x > begin().x) {
    a.x--;
    return a;
  }
  return begin();
}
