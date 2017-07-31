#include "../../include/container/LinesContainer.h"

LinesContainer::LinesContainer()
{
    #ifdef OBJECT
        std::cout<<"LinesContainer object created." << std::endl;
    #endif
}

LinesContainer* LinesContainer::instance = NULL;

LinesContainer* LinesContainer::getInstance() {
    if(!instance) {
        instance = new LinesContainer();
    }
    return instance;
}

LinesContainer::~LinesContainer()
{
    #ifdef OBJECT
        std::cout<<"LinesContainer object destroyed." << std::endl;
    #endif
}