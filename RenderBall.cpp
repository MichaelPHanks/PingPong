#include "RenderBall.hpp"
#include "rlutil.h"

RenderBall::RenderBall() {

  for (int i = 0; i < rlutil::trows() - 3; i++) {
    std::vector<bool> newVec;
    prevMap.push_back(newVec);
    for (int j = 0; j < rlutil::tcols() - 3; j++) {
      prevMap[i].push_back(false);
    }
  }
  // Render Top and Bottom walls

  for (std::uint8_t i = 0; i < rlutil::tcols() - 6; i++) {
    rlutil::locate(i + 3, rlutil::trows());
    rlutil::setChar('-');
    rlutil::locate(i + 3, 2);
    rlutil::setChar('-');
  }
}

void RenderBall::render(BallSim sim) {
  rlutil::hidecursor();

  // Render map that contains balls
  for (std::uint8_t i = 0; i < sim.getHeight(); i++) {
    for (std::uint8_t j = 0; j < sim.getWidth(); j++) {

      bool cell = sim.getCell(j, i);
      if (prevMap[i][j] != cell) {
        rlutil::locate(j + 3, i + 3);

        if (cell) {

          rlutil::setChar('0');
        } else {
          rlutil::setChar(' ');
        }
      }
      prevMap[i][j] = cell;
    }
  }

  // Render Player Side

  for (int k = 0; k < sim.getHeight(); k++) {
    rlutil::locate(2, k + 3);

    if (sim.getPlayerCell(k)) {
      rlutil::setChar('0');

    } else {
      rlutil::setChar(' ');
    }
  }

  rlutil::showcursor();
}
