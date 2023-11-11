#include "RenderBall.hpp"
#include "rlutil.h"

void RenderBall::render(BallSim sim) {
  rlutil::hidecursor();
  for (std::uint8_t i = 0; i < sim.getHeight(); i++) {
    for (std::uint8_t j = 0; j < sim.getWidth(); j++) {
      if (sim.getCell(j, i)) {
        rlutil::locate(j, i);
        rlutil::setChar('0');
      }
    }
  }

  rlutil::showcursor();
}
