#include <iostream>
#include <algorithm>
namespace top {
  struct p_t {
    int x, y;
  };
  struct Idraw {
    ~Idraw() = default;
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };
  struct Dot: Idraw {
    p_t begin() const override;
    p_t next(p_t) const override;
    explicit Dot(p_t dd);
    p_t o;
    Dot(int x, int y);
  };
  struct Vline: Idraw {
    Vline(p_t y1, p_t y2);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t ytop;
    p_t ybot;
  };
  struct Hline: Idraw {
    Hline(p_t x1, p_t x2);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t xleft;
    p_t xright;
  };
  struct Line45: Idraw {
    Line45(p_t left_bot, int size);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t left_bot;
    int size;
  };
  struct f_t {
    p_t aa;
    p_t bb;
  };
  bool operator==(p_t a, p_t b) {
    return a.x == b.x && a.y == b.y;
  }
  bool operator!=(p_t a, p_t b) {
    return !(a == b);
  }
  size_t get_points(const Idraw& d, p_t ** pts, size_t s);
  void make_f(Idraw ** b, size_t k);
  f_t frame(const p_t * ps, size_t s);
  char * canvas(f_t fr, char fill);
  void paint(char * cnv, f_t fr, p_t p, char fill);
  void flush(std::ostream& os, const char * cnv, f_t fr);
}
top::Dot::Dot(int x, int y) :
  Idraw(),
  o{x, y}
{}
top::Dot::Dot(p_t dd) : Idraw(), o{dd} 
{}
top::p_t top::Dot::begin() const{
  return o;
}
top::p_t top::Dot::next(p_t) const {
  return begin();
}
top::Vline::Vline(p_t y1, p_t y2) :
  ytop{y1.y > y2.y ? y1 : y2}, ybot{y1.y > y2.y ? y2 : y1}
{}
top::p_t top::Vline::begin() const {
  return ybot;
}
top::p_t top::Vline::next(p_t a) const {
  a.y++;
  if (a.y > ytop.y) {
    return begin();
  }
  return a;
}
top::Hline::Hline(p_t x1, p_t x2) :
  xleft{x1.x > x2.x ? x2 : x1}, xright{x1.x > x2.x ? x1 : x2}
{}
top::p_t top::Hline::begin() const {
  return xleft;
}
top::p_t top::Hline::next(p_t a) const {
  a.x++;
  if (a.x > xright.x) {
    return begin();
  }
  return a;
}
top::Line45::Line45(p_t left_bot, int size) :
  left_bot{left_bot}, size{size}
{}
top::p_t top::Line45::begin() const {
  return left_bot;
}
top::p_t top::Line45::next(p_t a) const {
  a.x++;
  a.y++;
  if (a.x - begin().x > size) {
    return begin();
  }
  return a;
}
void extend(top::p_t** pts, size_t s, top::p_t p) {
  top::p_t * res = new top::p_t[s+1];
  for (size_t i = 0; i < s; ++i) {
    res[i] = (*pts)[i];
  }
  res[s] = p;
  delete [] *pts;
  *pts = res;
}
size_t top::get_points(const Idraw& d, p_t ** pts, size_t s) {
  p_t p = d.begin();
  extend(pts, s, p);
  size_t delta = 1;
  while (d.next(p) != d.begin()) {
    p = d.next(p);
    extend(pts, s + delta, p);
    ++delta;
  }
  return delta;
}
void top::make_f(Idraw ** b, size_t k) {
  b[0] = new Vline({3, 8}, {3, 1});
  b[1] = new Dot(10, 10);
  b[2] = new Dot(-1, -1);
//  b[2] = new Dot(-2, -5);
}
top::f_t top::frame(const p_t* pts, size_t s) {
  if (!s) {
    throw std::logic_error("bad size");
  }
  int minx = pts[0].x, maxx = minx;
  int miny = pts[0].y, maxy = miny;
  for (size_t i = 1; i < s; ++i) {
    minx = std::min(minx, pts[i].x);
    maxx = std::max(maxx, pts[i].x);
    miny = std::min(miny, pts[i].y);
    maxy = std::max(maxy, pts[i].y);
  }
  p_t aa{minx, miny};
  p_t bb{maxx, maxy};
  return {aa, bb};
}
size_t rows(top::f_t fr) {
  return (fr.bb.y - fr.aa.y +1);
}
size_t cols(top::f_t fr) {
  return (fr.bb.x - fr.aa.x +1);
}
char * top::canvas(f_t fr, char fill) {
  char * cnv = new char[rows(fr) * cols(fr)];
  for (size_t i = 0; i < rows(fr)*cols(fr); ++i) {
      cnv [i] = fill;
  }
  return cnv;
}
void top::paint(char * cnv, f_t fr, p_t p, char fill) {
  int dx = p.x - fr.aa.x;
  int dy = fr.bb.y - p.y;
  cnv[dy * cols(fr) + dx] = fill;
}
void top::flush(std::ostream& os, const char* cnv, f_t fr) {
  for (size_t i = 0; i < rows(fr); ++i) {
    for (size_t j = 0; j < cols(fr); ++j) {
      os << cnv[i * cols(fr) + j];
    }
    os << "\n";
  }
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
