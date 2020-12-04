#include "BookList.h"
#include "InventoryIterator.h"

BookList::BookList() {}

BookList::~BookList() {}

Iterator* BookList::createIterator() {
    return new InventoryIterator(this->books);
}