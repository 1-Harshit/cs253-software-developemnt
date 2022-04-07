#include "student.hpp"

Student::Student() : User()
{
	this->fine = 0;
}

Student::Student(string name, string password) : User(name, password, 's')
{
	fine = 0;
	books.clear();
}

void Student::getBooks()
{
	for (Book *book : books)
	{
		book->display();
	}
}

void Student::issue(Book *book)
{
	books.push_back(book);
}

int Student::getBookCount()
{
	return books.size();
}

int Student::calculateFine()
{
	int x = 0;
	for (Book *book : books)
	{
		int fine = (time(0) - book->showDueDate()) / 86400 * 2;
		if (fine > 0)
		{
			x += fine;
		}
	}
	return x;
}