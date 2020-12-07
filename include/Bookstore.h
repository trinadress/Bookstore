#ifndef _BOOKSTORE_H_
#define _BOOKSTORE_H_

#include "BookList.h"
#include "BookRecord.h"
#include "InventoryIterator.h"

#include <vector>
#include <string>

class Bookstore {
	public:
		Bookstore();
		~Bookstore();
		void editTitle(BookRecord &br, std::string titl);
		void editAuthor(BookRecord &br,std::string auth);
		void editNumOfCopies(BookRecord &br,int num);
		void deleteBook(BookRecord &br);
		void deleteBook(int index);
		void addBook(BookRecord &br);
		int searchBook(BookRecord &br);
		BookRecord searchBook(int index);
		int searchBookByTitle(std::string titl);

		void print();

		InventoryIterator* it;

	protected:
		BookList* inventory;
};
#endif
