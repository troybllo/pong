
#ifndef CONTROL_SCHEME_H
#define CONTROL_SCHEME_H

#include "SDL_keycode.h"

struct ControlScheme {
  SDL_Keycode moveUp;
  SDL_Keycode moveDown;
  SDL_Keycode moveRight;
  SDL_Keycode moveLeft;
};

#endif
