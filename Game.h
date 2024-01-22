#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>

class Game
{
private:
    SDL_Window * window;
    SDL_Event e;
    bool running;

public:
    static SDL_Renderer * renderer;
    Game(char title[30], int width, int height, int background_R, int background_G, int background_B);
    ~Game();
    void handle_events();
    void update();
    void render();

    bool isRunning();

    int static width;
    int static height;

    int static r;
    int static g;
    int static b;
};
