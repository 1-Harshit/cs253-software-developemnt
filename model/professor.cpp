#include "professor.hpp"

Professor::Professor() : User()
{
	this->fine = 0;
}

Professor::Professor(string name, string password) : User(name, password, 'p')
{
	fine = 0;
	books.clear();
}

void Professor::getBooks()
{
	for (Book *book : books)
	{
		book->display();
	}
}

void Professor::issue(Book *book)
{
	books.push_back(book);
}

int Professor::calculateFine()
{
	int x = 0;
	for (Book *book : books)
	{
		int fine = (time(0) - book->showDueDate()) / 86400 * 5;
		if (fine > 0)
		{
			x += fine;
		}
	}
	return x;
}