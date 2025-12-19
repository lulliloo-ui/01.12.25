#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "idraw.hpp"
namespace top {
struct Square: Idraw {
    Square(p_t left_bot, int length);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t left_bot;
    int length;
    };
}
#endif
