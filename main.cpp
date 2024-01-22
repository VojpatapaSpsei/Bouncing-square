#include <stdio.h>
#include <SDL.h>
#include "Game.h"

int main(int argc, char * argv[])
{
    int FPS = 60;
    float delta_time = 1000/FPS;
    Uint32 start_time;
    int elapsed_time;

    int frame_count = 0;
    int elapsed_time_whole = 0;

    Game * game = new Game("bouncing square", 700, 700, 255, 255, 255);

    while(game->isRunning())
    {
        start_time = SDL_GetTicks();

        game->handle_events();
        game->update();
        game->render();

        elapsed_time = SDL_GetTicks()-start_time;
        if(elapsed_time<(int)delta_time)
        {
            SDL_Delay(delta_time-elapsed_time);
        }

        elapsed_time_whole+=SDL_GetTicks()-start_time;
        if(elapsed_time_whole >= 1000)
        {
            printf("FPS : %d \n", frame_count);
            elapsed_time_whole = 0;
            frame_count = 0;
        }
        frame_count++;
    }

    delete game;

    return 0;
}
