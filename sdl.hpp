#ifndef SDL_HPP
#define SDL_HPP
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
struct Color{
    int r,g,b,a;
    Color(int r, int g, int b, int a=255):r(r),g(g),b(b),a(a){}
};

struct Rect{
    int x,y,h,w;
};

void windowInitialize(char const *felirat, unsigned int szeles, unsigned int magas, SDL_Window** pwindow ,  SDL_Renderer** prenderer);
void clearscreen(SDL_Renderer *prenderer);
void drawRectangle(SDL_Renderer* renderer, const Rect& rect, Color color);
void updateScreen(SDL_Renderer* renderer);

#endif // SDL_HPP
