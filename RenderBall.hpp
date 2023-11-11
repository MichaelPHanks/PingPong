#include "Ball.hpp"
#include "BallSim.hpp"
#pragma once

class RenderBall {
public:
  RenderBall();
  void render(BallSim sim);

private:
  std::vector<std::vector<bool>> prevMap;
};