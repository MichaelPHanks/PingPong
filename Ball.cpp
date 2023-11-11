#include "Ball.hpp"

Ball::Ball(std::uint8_t x, std::uint8_t y) {

  current.first = x;
  current.second = y;

  if (x > 0 && y > 0) {
    prev.first = x - 1;
    prev.second = y - 1;
  }
}

Ball::Ball() {}

std::pair<std::uint8_t, std::uint8_t> Ball::getPrev() { return prev; }

std::pair<std::uint8_t, std::uint8_t> Ball::getCurrent() { return current; }

void Ball::setPrev(std::uint8_t x, std::uint8_t y) {
  prev.first = x;
  prev.second = y;
}

void Ball::setCurrent(std::uint8_t x, std::uint8_t y) {
  current.first = x;
  current.second = y;
}
