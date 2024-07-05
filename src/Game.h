
#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Player.h"
#include "SDL_stdinc.h"
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

  void setFrameStart(Uint32 start) { frameStart = start; }
  Uint32 getFrameStart() const { return frameStart; }
  int getFrameTime() const { return frameTime; }
  void setFrameTime(int time) { frameTime = time; }
  int getFrameDelay() const { return frameDelay; }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;

  int score;

  std::vector<Player *> players;
  std::vector<Ball *> balls;

  bool checkCollision(const SDL_Rect &a, const SDL_Rect &b);

  const int frameDelay = 1000 / 60;
  Uint32 frameStart;
  int frameTime;
};

#endif // GAME_H
