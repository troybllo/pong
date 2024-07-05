#include "Ball.h";
#include "SDL_rect.h"
#include "SDL_render.h"

Ball::Ball(int x, int y, int width, int height) : xVel(5), yVel(5) {
  rect = {x, y, width, height};
}

Ball::~Ball() {}

void Ball::update() {

  rect.x += xVel;
  rect.y += yVel;

  if (rect.y < 0 || rect.y + rect.h > 600) {
    yVel = -yVel;
  }

  if (rect.x < 0 || rect.x + rect.w > 800) {
    reset();
  }
}

void Ball::render(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderFillRect(renderer, &rect);
}

void Ball::reverseX() { xVel = -xVel; }

void Ball::reset() {
  rect.x = 320 - rect.w / 2;
  rect.y = 240 - rect.h / 2;
  xVel = -xVel; // Change direction when resetting
}

SDL_Rect Ball::getRect() const { return rect; }
