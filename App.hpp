#ifndef APP_HPP
#define APP_HPP
#include <algorithm>
#include <vector>
#include "sdl.hpp"
#include "Element.hpp"
#include "sortingalgorithms.hpp"

class App
{
    private:
        unsigned int width , height,elementCount;
        SDL_Window* window;
        SDL_Renderer* renderer;
        std::vector<Element> sortmeVector;
    public:
        App(unsigned int _width=800,unsigned int _height=600,unsigned int _elementCount=200);
        void visualizeSorting();
        ~App();
};

#endif // APP_H
