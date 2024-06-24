
#include "Game.h"
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false) {}

Game::~Game() { clean(); }

bool Game::init(const std::string &title, int width, int height,
                bool fullscreen) {
  int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, width, height, flags);
    if (window) {
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        isRunning = true;
      } else {
        std::cerr << "Renderer creation failed: " << SDL_GetError()
                  << std::endl;
        return false;
      }
    } else {
      std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
      return false;
    }
  } else {
    std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
    return false;
  }
  return true;
}

void Game::handleEvents() {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

void Game::update() {
  // Update game objects
}

void Game::render() {
  SDL_RenderClear(renderer);
  // Render game objects
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
