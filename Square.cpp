#include "Square.h"
#include "Game.h"

Square::Square(int aSize, int bSize, int R, int G, int B)
{
    dst.w = aSize;
    dst.h = bSize;
    dst.x = x_pos = Game::width/2-dst.w/2;
    dst.y = y_pos = Game::height/2-dst.h/2;

    r = R;
    g = G;
    b = B;

    bong = Mix_LoadWAV("sounds/hit.mp3");
    Mix_VolumeChunk(bong, 20);

    srand(time(NULL));

    int true_or_false = rand()%(1-0+1)+0;

    if(true_or_false)
    {
        x_speed = 3.3;
    }
    else
    {
        x_speed = -3.3;
    }

    true_or_false = rand()%(1-0+1)+0;

    if(true_or_false)
    {
        y_speed = 3.0;
    }
    else
    {
        y_speed = -3.0;
    }

}

void Square::update()
{
    if(x_pos+dst.w>=Game::width)
    {
        x_pos = Game::width-dst.w;
        x_speed *= -1;
        Mix_PlayChannel(-1, bong, 0);
        if(r == 0)
        {
            r=g=b=255;
            Game::r=Game::g=Game::b=0;
            printf("bum \n");
        }
        else
        {
            r=g=b=0;
            Game::r=Game::g=Game::b=255;
            printf("bum \n");
        }
    }
    if(y_pos+dst.h>=Game::height)
    {
        y_pos = Game::height-dst.h;
        y_speed *= -1;
        Mix_PlayChannel(-1, bong, 0);
        if(r == 0)
        {
            r=g=b=255;
            Game::r=Game::g=Game::b=0;
            printf("bum \n");
        }
        else
        {
            r=g=b=0;
            Game::r=Game::g=Game::b=255;
            printf("bum \n");
        }
    }
    if(x_pos<=0)
    {
        x_pos = 0;
        x_speed *= -1;
        Mix_PlayChannel(-1, bong, 0);
        if(r == 0)
        {
            r=g=b=255;
            Game::r=Game::g=Game::b=0;
            printf("bum \n");
        }
        else
        {
            r=g=b=0;
            Game::r=Game::g=Game::b=255;
            printf("bum \n");
        }
    }
    if(y_pos<=0 && !(y_pos+dst.h>=Game::height))
    {
        y_pos = 0;
        y_speed *= -1;
        Mix_PlayChannel(-1, bong, 0);
        if(r == 0)
        {
            r=g=b=255;
            Game::r=Game::g=Game::b=0;
            printf("bum \n");
        }
        else
        {
            r=g=b=0;
            Game::r=Game::g=Game::b=255;
            printf("bum \n");
        }
    }

    x_pos += x_speed;
    y_pos += y_speed;

    dst.x = (int)x_pos;
    dst.y = (int)y_pos;

}

void Square::render()
{
    SDL_SetRenderDrawColor(Game::renderer, r, g, b, 255);
    SDL_RenderFillRect(Game::renderer, &dst);
    SDL_SetRenderDrawColor(Game::renderer, Game::r, Game::g, Game::b, 255);
}