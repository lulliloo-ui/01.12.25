#include <iostream>
#include <algorithm>
#include "ascii_draw.hpp"
namespace top {
  using namespace top;
  void make_f(Idraw ** b, size_t k);
}
void top::make_f(Idraw ** b, size_t k) {
  b[0] = new Rectangle({1, 1}, 4, 3);
  b[1] = new Dot(10, 10);
  b[2] = new Dot(-1, -1);
//  b[2] = new Dot(-2, -5);
}
int main()
{
  using namespace top;
  Idraw * f[3] = {};
  p_t * p = nullptr;
  size_t s = 0;
  char * cnv = nullptr;
  int err = 0;
  try {
    make_f(f, 3);
    for (size_t i= 0; i < 3; ++i) {
      s += get_points(*(f[i]), & p, s);
    }
    f_t fr = frame(p, s);
    cnv = canvas(fr, '.');
    for (size_t i = 0; i < s; ++i) {
      paint(cnv, fr, p[i], '#');
    }
    flush(std::cout, cnv, fr);
  } catch(...) {
    err = 1;
  }
  delete f[0];
  delete f[1];
  delete f[2];
  delete[] p;
  delete[] cnv;
  return err;
}
