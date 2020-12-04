#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "BookRecord.h"

class Iterator {
    public:
        Iterator() {};
        ~Iterator() {};

        virtual BookRecord first() = 0;
        virtual BookRecord next() = 0;
        virtual BookRecord currentItem() = 0;
        virtual bool isDone() = 0;
};

#endif