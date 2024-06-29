#include "Ball.h";
#include "SDL_rect.h"
#include "SDL_render.h"

Ball::Ball(int x, int y, int width, int height) {
  rect = {x, y, width, height};
}

Ball::~Ball() {}

void Ball::update() {
  rect.x += 1;
  if (rect.x == 0 || 800) {
    rect.x -= 1;
  }
}

void Ball::render(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Ball::getRect() const { return rect; }
