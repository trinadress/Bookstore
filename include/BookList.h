#ifndef _BOOKLIST_H_
#define _BOOKLIST_H_

#include "Container.h"
#include "InventoryIterator.h"

#include <vector>

typedef std::vector<BookRecord> BookInventory;



class BookList : public Container {
    public:
        BookList();
        ~BookList();

        Iterator* createIterator();
        BookInventory books;
};

#endif