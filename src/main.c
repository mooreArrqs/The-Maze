#include <stdio.h>
#include <SDL2/SDL.h>

int SCREEN_WIDTH = 1260;
int SCREEN_HEIGHT = 720;

SDL_Window *window;
SDL_Renderer *renderer;

int init(void)
{
    /* initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Unable to initialize SDL:%s\n", SDL_GetError());
        return (1);
    }

    /* Create a new Window */
    window = SDL_CreateWindow("My Maze Game Yay \\o/",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL)
    {
            fprintf(stderr, "Create window error:%s\n", SDL_GetError());
            SDL_Quit();
            return (1);
    }
    //screen_surface = SDL_GetWindowSurface(window);

    /* Create a new Renderer instance linked to the Window */
    renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        SDL_DestroyWindow(window);
        fprintf(stderr, "Create renderer error:%s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }
    return (0);
}

int main(void)
{
	if (init() != 0)
        {
		printf("failed to init\n");
		return (1);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);


        SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
        SDL_Quit();
        return (0);
}
