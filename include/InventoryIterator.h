#ifndef _INVENTORYITERATOR_H_
#define _INVENTORYITERATOR_H_

#include "Iterator.h"
#include "BookRecord.h"

#include <vector>

typedef std::vector<BookRecord> BookInventory;

class InventoryIterator : public Iterator {
	public:
		InventoryIterator(BookInventory &b);
		~InventoryIterator();

		BookRecord first();
		BookRecord next();
		BookRecord currentItem();
		BookRecord last();
		int getCursor();
		bool isDone();
		void begin();
		int getSize();

	private:
		BookInventory* inventory;
		int cursor;
};

#endif
