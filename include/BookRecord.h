#ifndef _BOOKRECORD_H_
#define _BOOKRECORD_H_

#include "string"

class BookRecord {
	public:
		BookRecord();
		BookRecord(std::string titl, std::string auth, int num);
		int getId();
		std::string getTitle();
		std::string getAuthor();
		int getNumOfCopies();

		void setTitle(std::string titl);
		void setAuthor(std::string auth);
		void setNumOfCopies(int num);

		bool operator ==(const BookRecord &b1) {
			return (title == b1.title && author == b1.author 
				&& numOfCopies == b1.numOfCopies);
		}

	private:
		static int id;
		std::string title;
		std::string author;
		int numOfCopies;
};

#endif
