#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>
#include <time.h>
#include <stdlib.h>

class Square
{
private:
    float x_speed;
    float y_speed;
    float x_pos;
    float y_pos;
    SDL_Rect dst;
    int r;
    int g;
    int b;
    Mix_Chunk * bong;

public:
    Square(int aSize, int bSize, int R, int G, int B);
    ~Square();
    void update();
    void render();
};
