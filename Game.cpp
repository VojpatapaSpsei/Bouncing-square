#include "Game.h"
#include "Square.h"


SDL_Renderer * Game::renderer;
int Game::width;
int Game::height;

int Game::r;
int Game::g;
int Game::b;

Square * square;

Game::Game(char title[30], int Width, int Height, int background_R, int background_G, int background_B)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        printf("Something went wrong with SDL init");
        printf("%s \n", SDL_GetError());
        SDL_Delay(1000);
        exit(0);
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("Something went wrong with SDL_mixer init \n");
        printf("%s \n", Mix_GetError());
        SDL_Delay(1000);
        exit(0);
    }


    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, background_R, background_G, background_B, 255);
    r = background_R;
    g = background_G;
    b = background_B;

    width = Width;
    height = Height;

    square = new Square(50, 50, 0, 0, 0);

    running = true;
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::handle_events()
{
    while(SDL_PollEvent(&e))
    {
        if(e.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

void Game::update()
{
    SDL_GetWindowSize(window, &width, &height);

    square->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    square->render();

    SDL_RenderPresent(renderer);
}

bool Game::isRunning()
{
    return running;
}

