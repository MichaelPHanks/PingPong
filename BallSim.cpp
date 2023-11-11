#include "BallSim.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

BallSim::BallSim(std::uint8_t width, std::uint8_t height)
    : width(width), height(height) {
  for (std::uint8_t i = 0; i < height; i++) {
    std::vector<std::vector<Ball>> newVec;
    map.push_back(newVec);
    for (std::uint8_t j = 0; j < width; j++) {
      std::vector<Ball> evenNewerVec;
      map[i].push_back(evenNewerVec);
    }
  }
}

void BallSim::insertBall(Ball ball) {
  if (ball.getCurrent().first < width && ball.getCurrent().second < height) {
    map[ball.getCurrent().second][ball.getCurrent().first].push_back(ball);
  } else {
    throw std::invalid_argument("Ball dimensions are not within boundaries...");
  }
}

void BallSim::update() {
  std::vector<std::vector<std::vector<Ball>>> newMap;
  for (std::uint8_t i = 0; i < height; i++) {
    std::vector<std::vector<Ball>> newVec;
    newMap.push_back(newVec);
    for (std::uint8_t j = 0; j < width; j++) {
      std::vector<Ball> evenNewerVec;
      newMap[i].push_back(evenNewerVec);
    }
  }

  for (std::uint8_t i = 0; i < height; i++) {
    for (std::uint8_t j = 0; j < width; j++) {
      if (map[i][j].size() > 0) {
        for (unsigned int k = 0; k < map[i][j].size(); k++) {

          Ball ball = map[i][j][k];
          std::pair<std::uint8_t, std::uint8_t> prev = ball.getPrev();
          std::pair<std::uint8_t, std::uint8_t> current = ball.getCurrent();
          ball.setPrev(current.first, current.second);
          int newX = current.first - prev.first;
          int newY = current.second - prev.second;

          ball.setCurrent(current.first + newX, current.second + newY);
          newMap[current.second + newY][current.first + newX].push_back(ball);
        }
      }
    }
  }

  map = newMap;
}

bool BallSim::getCell(std::uint8_t x, std::uint8_t y) {
  if (x > width - 1 || y > height - 1) {
    return false;
  }
  if (map[y][x].size() > 0) {
    return true;
  }
  return false;
}

std::uint8_t BallSim::getWidth() { return width; }

std::uint8_t BallSim::getHeight() { return height; }
