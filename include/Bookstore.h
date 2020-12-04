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
		void addBook(BookRecord br);
		void editTitle(BookRecord &br, std::string titl);
		void editAuthor(BookRecord &br,std::string auth);
		void editNumOfCopies(BookRecord &br,int num);
		void deleteBook(BookRecord &br);
		int searchBook(BookRecord &br);
		int searchBookByTitle(std::string titl);

		void print();

	private:
		BookList* inventory;
		InventoryIterator* it;
};
#endif
