#include "App.hpp"

App:: App(unsigned int _width,unsigned int _height,unsigned int _elementCount) {
    width=_width;
    height=_height;
    elementCount=_elementCount;
    windowInitialize("Tomb rendezes vizualizalo", width, height, &window, &renderer);

}

void App::visualizeSorting() {

    for(unsigned int i =0;  i<elementCount; ++i) {
        unsigned int value=rand() % elementCount + 1;
        sortmeVector.push_back(Element(value, i, elementCount, width, height, renderer));
    }

    SelectionSort(sortmeVector, elementCount);

    shuffle(sortmeVector,elementCount);
    MergeSort(sortmeVector,0,elementCount-1);

    shuffle(sortmeVector,elementCount);
    BubbleSort(sortmeVector,elementCount);


    shuffle(sortmeVector,elementCount);
    InsertionSort(sortmeVector);

    shuffle(sortmeVector,elementCount);
    std::sort(sortmeVector.begin(),sortmeVector.end());



    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
    }
    SDL_Quit();
}

App::~App() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
