#include "Ball.hpp"
#include "BallSim.hpp"
#include "RenderBall.hpp"
#include "rlutil.h"
#include <iostream>
#include <thread>

int main() {

  // tcols is 120 or so, trows is 30 or so, x = 120, y = 30
  BallSim sim = BallSim(rlutil::tcols(), rlutil::trows());
  Ball firstBall = Ball(10, 10);
  sim.insertBall(firstBall);
  sim.insertBall(Ball(12, 10));
  RenderBall renderer;
  renderer.render(sim);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  sim.update();
  renderer.render(sim);

  while (true) {
  }
}