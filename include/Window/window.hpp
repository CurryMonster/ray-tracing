#pragma once

#define SDL_MAIN_HANDLED

#include "SDL.h"

class Window 
{
    public:
        // width must equal height
        // width/height must equal vertical/horizontal resolution of ViewPlane!
        Window(int width, int height);
        ~Window();
    private:
        SDL_Window*   window;
        SDL_Renderer* renderer;
        SDL_Event     event;
        SDL_bool      done;
        int           width;
        int           height;
};

