#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "idraw.hpp"
namespace top {
  struct Rectangle: Idraw {
    Rectangle(p_t left_bot, int length_a, int length_b);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t left_bot;
    int length_a;
    int length_b;
    };
}
#endif
