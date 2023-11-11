#include "Ball.hpp"
#include "BallSim.hpp"
#include "RenderBall.hpp"
#include "rlutil.h"
#include <iostream>
#include <thread>

int main() {

  // tcols is 120 or so, trows is 30 or so, x = 120, y = 30
  BallSim sim = BallSim(rlutil::tcols() - 3, rlutil::trows() - 3);
  Ball firstBall = Ball(10, 10);
  sim.insertBall(firstBall);
  sim.insertBall(Ball(1, 1));
  RenderBall renderer;

  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    sim.update();
    renderer.render(sim);
    char key = rlutil::nb_getch();
    sim.movePlayer(key);
  }
}