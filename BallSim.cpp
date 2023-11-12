#include "BallSim.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

BallSim::BallSim(std::uint8_t width, std::uint8_t height)
    : width(width), height(height), playerSize(height / 5) {
  for (std::uint8_t i = 0; i < height; i++) {
    playerMap.push_back(false);
    std::vector<std::vector<Ball>> newVec;
    map.push_back(newVec);
    for (std::uint8_t j = 0; j < width; j++) {
      std::vector<Ball> evenNewerVec;
      map[i].push_back(evenNewerVec);
    }
  }

  for (int l = 0; l < playerSize; l++) {
    playerMap.at(l) = true;
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

          int newX = current.first - prev.first;
          int newY = current.second - prev.second;

          // Things to still implement: corner cases

          // If we hit the right side of the map (enemy)
          if (current.first + newX >= width) {
            if (newX == 1 && newY == 1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first - 1, current.second + 1);
              newMap[current.second + 1][current.first - 1].push_back(ball);
            } else if (newX == 1 && newY == -1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first - 1, current.second - 1);
              newMap[current.second - 1][current.first - 1].push_back(ball);
            }
          }
          // If we hit the bottom of the map
          else if (current.second + newY >= height) {
            if (newX == 1 && newY == 1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first + 1, current.second - 1);
              newMap[current.second - 1][current.first + 1].push_back(ball);
            } else if (newX == -1 && newY == 1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first - 1, current.second - 1);
              newMap[current.second - 1][current.first - 1].push_back(ball);
            }
          }
          // If we hit the top of the map
          else if (current.second + newY < 0) {
            if (newX == 1 && newY == -1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first + 1, current.second + 1);
              newMap[current.second + 1][current.first + 1].push_back(ball);
            } else if (newX == -1 && newY == -1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first - 1, current.second + 1);
              newMap[current.second + 1][current.first - 1].push_back(ball);
            }

          }
          // If we hit the left side of the map (player)
          else if (current.first + newX < 0) {
            if (newX == -1 && newY == 1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first + 1, current.second + 1);
              newMap[current.second + 1][current.first + 1].push_back(ball);
            } else if (newX == -1 && newY == -1) {
              ball.setPrev(current.first, current.second);
              ball.setCurrent(current.first + 1, current.second - 1);
              newMap[current.second - 1][current.first + 1].push_back(ball);
            }
          }

          else {
            ball.setPrev(current.first, current.second);

            ball.setCurrent(current.first + newX, current.second + newY);

            newMap[current.second + newY][current.first + newX].push_back(ball);
          }
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

std::uint8_t BallSim::getPlayerSize() { return playerSize; }

bool BallSim::getPlayerCell(std::uint8_t y) { return playerMap[y]; }

void BallSim::movePlayer(char input) {
  if (input == 'w') {
    if (!playerMap[0]) {
      int location{};
      for (int i = 0; i < playerMap.size(); i++) {
        if (playerMap[i]) {
          location = i;
          break;
        }
      }
      for (int j = 0; j < playerSize; j++) {

        playerMap[location - 1] = true;
        playerMap[location] = false;
        location += 1;
      }
    }
  } else if (input == 's') {
    if (!playerMap[playerMap.size() - 1]) {
      int location{};
      for (int i = playerMap.size() - 1; i > 0; i--) {
        if (playerMap[i]) {
          location = i;
          break;
        }
      }
      for (int j = 0; j < playerSize; j++) {
        playerMap[location + 1] = true;
        playerMap[location] = false;
        location--;
      }
    }
  }
}
