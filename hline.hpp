#ifndef HLINE_HPP
#define HLINE_HPP
#include "idraw.hpp"
namespace top {
  struct Hline: Idraw {
    Hline(p_t x, int size);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t xleft;
    int size;
  };
}
#endif
