#include "BookRecord.h"
#include <iostream>

BookRecord::BookRecord() : title(""), author(""), numOfCopies(0)
{}

BookRecord::BookRecord(std::string titl, std::string auth, int num) :
		title(titl), author(auth), numOfCopies(num)
{}

int BookRecord::getId() {
	return id;
}

std::string BookRecord::getTitle() {
	return title;
}

std::string BookRecord::getAuthor() {
	return author;
}

int BookRecord::getNumOfCopies() {
	return numOfCopies;
}

void BookRecord::setTitle(std::string titl) {
	title = titl;
}

void BookRecord::setAuthor(std::string auth) {
	author = auth;
}

void BookRecord::setNumOfCopies(int num) {
	numOfCopies = num;
}

int BookRecord::id = 0;
