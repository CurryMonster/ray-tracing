#include "Window/window.hpp"
#include "World/world.hpp"

Window::Window(int width, int height) : window {NULL}, renderer {NULL}, event {}, done {SDL_FALSE}, width {width}, height {height}
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        if (SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) == 0)
        {
            while (!done)
            {
                // do stuff here...
                World w;
                w.build();
                w.render_scene(renderer);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                }
            }
        }
    }
}

Window::~Window()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }
        
    if (window)
    {
        SDL_DestroyWindow(window); 
    }

    SDL_Quit();
}

