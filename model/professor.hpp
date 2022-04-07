#pragma once

#include "user.hpp"
#include "book.hpp"
#include <vector>

class Professor : public User
{
private:
	int fine;
	vector<Book* > books;

public:
	Professor();
	Professor(string name, string password);
	void issue(Book *book);
	int getFine();
	int calculateFine();
	void clearFineAmount();
	void getBooks();
};
