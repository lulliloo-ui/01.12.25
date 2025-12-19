#ifndef GEOM_HPP
#define GEOM_HPP
#include <cstddef>
namespace top {
  struct p_t {
    int x, y;
  };
  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);
  struct f_t {
    p_t aa;
    p_t bb;
  };
  size_t rows(top::f_t fr);
  size_t cols(top::f_t fr);
  f_t frame(const p_t* pts, size_t s);
}
#endif