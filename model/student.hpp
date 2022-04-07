#pragma once

#include "user.hpp"
#include "book.hpp"
#include <vector>

class Student : public User
{
private:
	int fine;
	vector<Book> books;

public:
	Student();
	Student(string name, string password);
	void issue(Book book);
	int getFine();
	int calculateFine();
	void clearFineAmount();
};
