#ifndef VLINE_HPP
#define VLINE_HPP
#include "idraw.hpp"
namespace top {
  struct Vline: Idraw {
    Vline(p_t y, int size);
    p_t begin() const override;
    p_t next(p_t) const override;
    int size;
    p_t ybot;
  };
}
#endif