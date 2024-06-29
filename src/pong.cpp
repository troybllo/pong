
#include "Ball.h"
#include "Game.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_rect.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Game::Game()
    : window(nullptr), renderer(nullptr), isRunning(false), player(nullptr),
      ball(nullptr), score(0) {}

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

        // Initialize SDL_image
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          SDL_Log("Unable to initialize SDL_image: %s", IMG_GetError());
          SDL_Quit();
          return false;
        }

        // Initialize SDL_mixer
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
          SDL_Log("Unable to initialize SDL_mixer: %s", Mix_GetError());
          IMG_Quit();
          SDL_Quit();
          return false;
        }

        player = new Player(0, 100, 25, 100);
        players.push_back(new Player(800, 100, 25, 100));
        ball = new Ball(450, 300, 30, 30);

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
  bool quit = false;
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
    case SDLK_ESCAPE:
      isRunning = false;
      break;
    default:
      break;
    }
    player->handleInput(event);
  }
}

void Game::update() {
  player->update();
  ball->update();

  if (checkCollision(player->getRect(), ball->getRect())) {
    std::cout << "Collision detected!" << std::endl;

    score += 1; // Increment score
    std::cout << "Score: " << score << std::endl;

    ball->~Ball();
    ball = new Ball(rand() % 200, 0, 50, 50);
  }
  // Update game objects
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  player->render(renderer);
  ball->render(renderer);

  for (auto &ball : balls) {
    ball->render(renderer);
  }

  // Render game objects
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  delete player;

  for (auto &ball : balls) {
    delete ball;
  }

  balls.clear();

  Mix_CloseAudio();
  IMG_Quit();
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

bool Game::checkCollision(const SDL_Rect &a, const SDL_Rect &b) {
  return (a.x < b.x + b.w && a.x + a.w > b.x && a.y < b.y + b.h &&
          a.y + a.h > b.y);
}
