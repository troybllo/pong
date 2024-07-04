
#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Player.h"
#include <SDL2/SDL.h>
#include <string>
#include <vector>

class Game {
public:
  Game();
  ~Game();

  bool init(const std::string &title, int width, int height, bool fullscreen);
  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() { return isRunning; }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;

  int score;

  std::vector<Player *> players;
  std::vector<Ball *> balls;

  bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);
};

#endif // GAME_H
