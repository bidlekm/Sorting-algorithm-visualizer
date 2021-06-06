#include "Element.hpp"

Element::Element(unsigned int _height,unsigned int index, unsigned int elementCount,unsigned int sWidth,unsigned int sHeight, SDL_Renderer* _renderer){
    height = _height;
    rect.x = index * sWidth / elementCount;
    rect.y = sHeight - (height * (sHeight / elementCount));
    rect.w = sWidth / elementCount;
    rect.h = height * (sHeight / elementCount);
    renderer = _renderer;
    drawRectangle(renderer,rect,Color(255,255,255));
    updateScreen(renderer);
}

bool Element::operator < (const Element& e){
 return height < e.height;
}

bool Element::operator > (const Element& e){
 return !(*this < e);
}

Element& Element::operator =(const Element& e){
    if(renderer==nullptr){
        height=e.height;
        rect=e.rect;
        renderer=e.renderer;
    }
    else{
        drawRectangle(renderer, rect, Color(0,0,0));
        height=e.height;
        rect.y=e.rect.y;
        rect.h=e.rect.h;
        drawRectangle(renderer, rect, Color(255,255,255));
        updateScreen(renderer);
    }
    return *this;
}

