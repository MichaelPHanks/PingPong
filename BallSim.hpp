#include "Ball.hpp"
#include <cstdint>
#include <vector>
#pragma once

class BallSim {
public:
  BallSim(std::uint8_t width, std::uint8_t height);
  void insertBall(Ball ball);
  void update();
  bool getCell(std::uint8_t x, std::uint8_t y);
  std::uint8_t getWidth();
  std::uint8_t getHeight();

private:
  std::vector<std::vector<std::vector<Ball>>> map;
  std::uint8_t width;
  std::uint8_t height;
};