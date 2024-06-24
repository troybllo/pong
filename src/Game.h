
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <string>

class Game {
public:
  Game();
  ~Game();

  bool init(const std::string &title, int width, int height, bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();
  bool running() const { return isRunning; }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;
};

#endif // GAME_H
