
#include "Game.h"
#include "SDL_timer.h"
#include <SDL2/SDL.h>

Game *game = nullptr;

int main(int argc, char *argv[]) {
  game = new Game();

  if (game->init("pong", 800, 600, false)) {
    while (game->running()) {
      game->setFrameStart(SDL_GetTicks());
      game->handleEvents();
      game->update();
      game->render();

      game->setFrameTime(SDL_GetTicks() - game->getFrameStart());

      if (game->getFrameDelay() > game->getFrameTime()) {
        SDL_Delay(game->getFrameDelay() - game->getFrameTime());
      }
    }
  }

  game->clean();
  return 0;
}
