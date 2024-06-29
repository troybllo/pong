
#include "Player.h"

Player::Player(int x, int y, int width, int height) : speed(15) {
  rect = {x, y, width, height};
}

Player::~Player() {}

void Player::handleInput(const SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
    case SDLK_w:
      rect.y -= speed;
      break;
    case SDLK_s:
      rect.y += speed;
      break;
    case SDLK_a:
      rect.x -= speed;
      break;
    case SDLK_d:
      rect.x += speed;
      break;
    }
  }
}

void Player::update() {
  // Additional update logic if needed
}

void Player::render(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(renderer, &rect);
}

SDL_Rect Player::getRect() const { return rect; }
