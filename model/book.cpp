#include "book.hpp"

#include <iostream>

Book::Book()
{
}

Book::Book(string title, string author, string isbn, string publication)
{
	this->title = title;
	this->author = author;
	this->isbn = isbn;
	this->publication = publication;
	this->user = new User();
}

void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setIsbn(string isbn)
{
	this->isbn = isbn;
}

void Book::setPublication(string publication)
{
	this->publication = publication;
}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setUser(User *user)
{
	this->user = user;
}

void Book::setDate(long date)
{
	this->date = date;
}

string Book::getAuthor()
{
	return author;
}

string Book::getIsbn()
{
	return isbn;
}

string Book::getPublication()
{
	return publication;
}

string Book::getTitle()
{
	return title;
}

User *Book::getUser()
{
	return user;
}

long Book::showDueDate()
{
	return date;
}

bool Book::bookRequest(User *user)
{
	if (this->date == 0)
	{
		this->user = user;
		this->date = time(0);
		return true;
	}
	else
	{
		return false;
	}
}

void Book::display()
{
	cout << "Title: " << title << endl;
	cout << "Publication: " << publication << endl;
	cout << "Author: " << author << endl;
	cout << "ISBN: " << isbn << endl;
	cout << "Issued To: " << user->getName() << endl;
}
