
#ifndef PLAYER_H
#define PLAYER_H

#include "ControlScheme.h"
#include <SDL2/SDL.h>

class Player {
public:
  Player(int x, int y, int width, int height, ControlScheme controls);
  ~Player();

  void handleInput(const SDL_Event &event);
  void update();
  void render(SDL_Renderer *renderer);

  SDL_Rect getRect() const;

private:
  SDL_Rect rect;
  int speed;
  ControlScheme controlScheme;
};

#endif // PLAYER_H
