#include "Ball.hpp"
#include "BallSim.hpp"
#pragma once

class RenderBall {
public:
  void render(BallSim sim);

private:
  std::vector<std::vector<std::vector<Ball>>> prevMap;
};