#ifndef LINE45_HPP
#define LINE45_HPP
#include "idraw.hpp"
namespace top {
  struct Line45: Idraw {
    Line45(p_t left_bot, int size);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t left_bot;
    int size;
  };
}
#endif