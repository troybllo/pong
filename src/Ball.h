
#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

class Ball {
public:
  Ball(int x, int y, int width, int height);
  ~Ball();

  void update();
  void render(SDL_Renderer *renderer);

  SDL_Rect getRect() const;

private:
  SDL_Rect rect;
};

#endif // ENEMY_H
