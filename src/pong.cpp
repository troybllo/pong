
#include "Ball.h"
#include "ControlScheme.h"
#include "Game.h"
#include "Player.h"
#include "SDL.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_rect.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false), score(0) {}

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

        ControlScheme player1Controls = {SDLK_w, SDLK_s, SDLK_d, SDLK_a};
        ControlScheme player2Controls = {SDLK_UP, SDLK_DOWN, SDLK_RIGHT,
                                         SDLK_LEFT};

        players.push_back(new Player(0, 100, 25, 100, player1Controls));
        players.push_back(new Player(773, 100, 25, 100, player2Controls));
        balls.push_back(new Ball(400, 300, 20, 30));

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
    case SDLK_q:
      isRunning = false;
    default:
      break;
    }

    for (auto &player : players) {
      player->handleInput(event);
    }
  }
}

void Game::update() {

  for (auto &player : players) {
    player->update();
  }

  for (auto &ball : balls) {
    ball->update();
    // Check collision with player

    for (auto &player : players) {
      if (checkCollision(player->getRect(), ball->getRect())) {
        std::cout << "Collision detected!" << std::endl;
        score += 1;                                   // Increment score
        std::cout << "Score: " << score << std::endl; // Print score to console
        // Handle collision (e.g., reset enemy position)
        ball->~Ball();
        ball = new Ball(rand() % 600, 0, 50,
                        50); // Randomize enemy's new x position
      }
    }

    // Update game objects
  }
}

void Game::render() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  for (auto &ball : balls) {
    ball->render(renderer);
  }

  for (auto &player : players) {
    player->render(renderer);
  }

  // Render game objects
  SDL_RenderPresent(renderer);
}

void Game::clean() {

  for (auto &ball : balls) {
    delete ball;
  }

  for (auto &player : players) {
    delete player;
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
