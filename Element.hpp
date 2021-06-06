#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include "sdl.hpp"

class Element
{
    private:
        unsigned int height;
        Rect rect;
        SDL_Renderer* renderer = nullptr;
    public:
        Element()= default;
        Element(const Element&) = default;
        Element(unsigned int height,unsigned int index, unsigned int elementCount,unsigned int sWidth,unsigned int sHeight, SDL_Renderer* _renderer);
        bool operator < (const Element& e);
        bool operator > (const Element& e);
        Element& operator =(const Element& e);
        ~Element(){}
};

#endif // ELEMENT_HPP
