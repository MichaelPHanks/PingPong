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
  std::uint8_t getPlayerSize();
  bool getPlayerCell(std::uint8_t y);
  void movePlayer(char input);

private:
  std::vector<std::vector<std::vector<Ball>>> map;
  std::vector<bool> playerMap;
  std::uint8_t playerSize;
  std::uint8_t width;
  std::uint8_t height;
};