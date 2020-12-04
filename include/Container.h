#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "Iterator.h"

class Container {
    public:
        Container() {};
        ~Container() {};

        virtual Iterator* createIterator() = 0;
};

#endif