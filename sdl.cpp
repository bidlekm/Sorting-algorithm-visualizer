#include "sdl.hpp"

void windowInitialize(char const *felirat, unsigned int szeles, unsigned int magas, SDL_Window** pwindow ,  SDL_Renderer** prenderer){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());

    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL) {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());

    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());

    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer =  renderer;
}

void clearscreen(SDL_Renderer *prenderer){
    SDL_SetRenderDrawColor(prenderer, 0, 0, 0, 255 );
    SDL_RenderClear(prenderer);
    SDL_SetRenderDrawColor(prenderer, 255, 255, 255, 255 );
}

void drawRectangle(SDL_Renderer* renderer, const Rect& rect, Color color){
    SDL_Rect sdlRect;
    sdlRect.x=rect.x;
    sdlRect.y=rect.y;
    sdlRect.w=rect.w;
    sdlRect.h=rect.h;
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a );
    SDL_RenderFillRect(renderer, &sdlRect);
}

void updateScreen(SDL_Renderer* renderer){
    SDL_RenderPresent(renderer);
}
