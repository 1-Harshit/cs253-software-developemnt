#include "model/book.hpp"
#include <vector>

class BookDB
{
private:
	vector<Book> books;

public:
	BookDB();
	void add(Book book);
	bool update(Book book, string ISBN);
	bool remove(string ISBN);
	vector<Book> search(Book book);
	bool requestBook(User user, string ISBN, long date);
	long getDueDate(string ISBN);
};

BookDB::BookDB()
{
	books.clear();
}

void BookDB::add(Book book)
{
	books.push_back(book);
}

bool BookDB::update(Book book, string ISBN)
{
	if (book.getIsbn() != ISBN)
		return false;

	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getIsbn() == ISBN)
		{
			books[i] = book;
			return true;
		}
	}

	return false;
}

bool BookDB::remove(string ISBN)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].getIsbn() == ISBN)
		{
			books.erase(books.begin() + i);
			return true;
		}
	}

	return false;
}

vector<Book> BookDB::search(Book book)
{
	vector<Book> result;

	if (book.getIsbn() != "")
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].getIsbn() == book.getIsbn())
				result.push_back(books[i]);
		}
	}

	if (book.getTitle() != "")
	{
		string title = book.getTitle();
		for (Book bookItem : books)
		{
			if (bookItem.getTitle().find(title) != string::npos)
				result.push_back(bookItem);
		}
	}

	if (book.getAuthor() != "")
	{
		string author = book.getAuthor();
		for (Book bookItem : books)
		{
			if (bookItem.getAuthor().find(author) != string::npos)
				result.push_back(bookItem);
		}
	}

	if (book.getPublication() != "")
	{
		string publication = book.getPublication();
		for (Book bookItem : books)
		{
			if (bookItem.getPublication().find(publication) != string::npos)
				result.push_back(bookItem);
		}
	}

	return result;
}

bool BookDB::requestBook(User user, string ISBN, long dueDate)
{
	for (Book book : books)
	{
		if (book.getIsbn() == ISBN)
		{
			if (book.getUser().getName() != "")
				return false;
			book.setUser(user);
			book.setDate(dueDate);
			return true;
		}
	}
	return false;
}

long BookDB::getDueDate(string ISBN)
{
	for (Book book : books)
	{
		if (book.getIsbn() == ISBN)
			return book.showDueDate();
	}
	return -1;
}
