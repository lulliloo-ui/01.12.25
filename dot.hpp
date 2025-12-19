#ifndef DOT_HPP
#define DOT_HPP
#include "idraw.hpp"
namespace top {
  struct Dot: Idraw {
    p_t begin() const override;
    p_t next(p_t) const override;
    explicit Dot(p_t dd);
    p_t o;
    Dot(int x, int y);
  };
}
#endif
