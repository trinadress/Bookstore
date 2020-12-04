#include <iostream>
#include "InventoryIterator.h"

InventoryIterator::InventoryIterator(BookInventory &b) {
    inventory = &b;
    cursor = 0;
}

InventoryIterator::~InventoryIterator() {}

BookRecord InventoryIterator::first() {
    return (*inventory)[0];
}

BookRecord InventoryIterator::next() {
    cursor++;
    if (isDone()) {
        return (*inventory)[inventory->size()-1];
    } else {
        return (*inventory)[cursor];
    }
}

BookRecord InventoryIterator::currentItem() {
    return (*inventory)[cursor];
}

BookRecord InventoryIterator::last() {
    return (*inventory)[inventory->size()-1];
}

int InventoryIterator::getCursor() {
    return cursor;
}

bool InventoryIterator::isDone() {
    return cursor >= inventory->size();
}

void InventoryIterator::begin() {
    cursor = 0;
}

int InventoryIterator::getSize() {
    return inventory->size();
}