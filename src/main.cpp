
#include "Game.h"
#include <SDL2/SDL.h>

Game *game = nullptr;

int main(int argc, char *argv[]) {
  game = new Game();

  if (game->init("SDL2 Game", 800, 600, false)) {
    while (game->running()) {
      game->handleEvents();
      game->update();
      game->render();
    }
  }

  game->clean();
  return 0;
}
