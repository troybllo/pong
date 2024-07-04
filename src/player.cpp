
#include "Player.h"
#include "ControlScheme.h"

Player::Player(int x, int y, int width, int height, ControlScheme controls)
    : speed(25), controlScheme(controls) {
  rect = {x, y, width, height};
}

Player::~Player() {}

void Player::handleInput(const SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == controlScheme.moveUp) { // Move up
      rect.y -= speed;
    } else if (event.key.keysym.sym == controlScheme.moveDown) { // Move down
      rect.y += speed;
    } else if (event.key.keysym.sym == controlScheme.moveLeft) { // Move left
      rect.x -= speed;
    } else if (event.key.keysym.sym == controlScheme.moveRight) { // Move right
      rect.x += speed;
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
