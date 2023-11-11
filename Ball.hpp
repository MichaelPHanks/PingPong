#include <cstdint>
#include <utility>
#pragma once
class Ball {
public:
  Ball(std::uint8_t x, std::uint8_t y);
  Ball();
  std::pair<std::uint8_t, std::uint8_t> getPrev();
  std::pair<std::uint8_t, std::uint8_t> getCurrent();
  void setPrev(std::uint8_t x, std::uint8_t y);
  void setCurrent(std::uint8_t x, std::uint8_t y);

private:
  std::pair<std::uint8_t, std::uint8_t> prev;
  std::pair<std::uint8_t, std::uint8_t> current;
};