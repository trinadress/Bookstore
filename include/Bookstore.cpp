#include "Bookstore.h"

#include <iostream>

Bookstore::Bookstore() {
	inventory = new BookList();
	it = new InventoryIterator(inventory->books);
	std::cerr << "Bookstore constructor called" << std::endl;
}

Bookstore::~Bookstore() {
	delete it;
}

void Bookstore::addBook(BookRecord br) {
	inventory->books.push_back(br);
}

void Bookstore::editTitle(BookRecord &br, std::string titl) {
	int i = searchBook(br);
	if(-1 != i) {
		inventory->books[i].setTitle(titl);
	} else {
		std::cerr << "book not found" << std::endl;
	}
}

void Bookstore::editAuthor(BookRecord &br, std::string auth) {
		int i = searchBook(br);
	if(-1 != i) {
		inventory->books[i].setAuthor(auth);
	} else {
		std::cerr << "book not found" << std::endl;
	}
}

void Bookstore::editNumOfCopies(BookRecord &br, int num) {
		int i = searchBook(br);
	if(-1 != i) {
		inventory->books[i].setNumOfCopies(num);
	} else {
		std::cerr << "book not found" << std::endl;
	}
}

void Bookstore::deleteBook(BookRecord &br) {
	int i = searchBookByTitle(br.getTitle());
	if (-1 != i) {
		inventory->books.erase(inventory->books.begin()+i);
	}
}

int Bookstore::searchBook(BookRecord &br) {
	it->begin();
	BookRecord b = it->first();
	while (!it->isDone()) {
		if (br == b) {
			return it->getCursor();
		} else {
			b = it->next();
		}
	}
	return -1;
}

int Bookstore::searchBookByTitle(std::string titl) {
	BookRecord b = it->first();
	while (!it->isDone()) {
		if (titl == b.getTitle()) {
			return it->getCursor();
		} else {
			b = it->next();
		}
	}
	return -1;
}

void Bookstore::print() {
	it->begin();
	while (!it->isDone()) {
		std::cout << "\nid: " << it->currentItem().getId()
			<< "\ntitle: " << it->currentItem().getTitle() 
			<< "\nauthor: " << it->currentItem().getAuthor() 
			<< "\nnumber of copies: " << it->currentItem().getNumOfCopies()  << std::endl;
		it->next();
	}
}
