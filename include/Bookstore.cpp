#include "Bookstore.h"

#include <iostream>

Bookstore::Bookstore() {
	inventory = new BookList();
	it = new InventoryIterator(inventory->books);
	BookRecord mat("Matilda", "Roald Dahl", 5);
	BookRecord q("1Q84", "Haruki Murakami", 2);
	BookRecord jaws("Jaws", "Peter Benchley", 9);
	BookRecord drac("Dracula", "Bram Stroker", 6);
	BookRecord frank("Frankenstein", "Mary Shelly", 14);
	BookRecord twi("Twilight", "Stephanie Meyer", 10);
	BookRecord deep("The Deep", "Peter Benchley", 3);
	BookRecord cat("The Cat in the Hat", "Dr. Seuss", 18);
	BookRecord fahr("Fahrenheit 451", "Ray Bradbury", 23);
	BookRecord wind("The Wind-up Bird Chronicle", "Haruki Murakami", 7);
	BookRecord kafka("Kafka on the Shore", "Haruki Murakami", 8);
	BookRecord hunch("The Hunchback of Notre Dame", "Victor Hugo", 4);
	BookRecord drag("The Girl with the Dragon Tattoo", "Steig Larsson", 7);
	BookRecord fire("The Girl Who Played With Fire", "Steig Larsson", 4);
	BookRecord mob("Moby Dick", "Herman Melville", 9);
	BookRecord east("The East of Eden", "John Steinbeck", 12);

	addBook(mat);
	addBook(q);
	addBook(jaws);
	addBook(drac);
	addBook(frank);
	addBook(twi);
	addBook(deep);
	addBook(cat);
	addBook(fahr);
	addBook(wind);
	addBook(kafka);
	addBook(hunch);
	addBook(drag);
	addBook(fire);
	addBook(mob);
	addBook(east);
}

Bookstore::~Bookstore() {
	delete it;
}

void Bookstore::addBook(BookRecord &br) {
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

void Bookstore::deleteBook(int index) {
	if (0 <= index && inventory->books.size() > index && !inventory->books.empty()) {
		inventory->books.erase(inventory->books.begin()+index);
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

BookRecord Bookstore::searchBook(int index) {
	if (0 <= index && inventory->books.size() > index && !inventory->books.empty()) {
		return inventory->books[index];
	}
}

int Bookstore::searchBookByTitle(std::string titl) {
	it->begin();
	BookRecord b = it->first();
	std::cout << b.getTitle() << " " << titl << std::endl;
	std::cout << it->isDone() << std::endl;
	std::cout << it->getCursor() << std::endl;
	while (!it->isDone()) {
		std::cout << b.getTitle() << " " << titl << std::endl;
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
