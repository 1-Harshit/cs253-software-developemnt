#pragma once
#include "user.hpp"
#include <string>

using namespace std;

class Book
{
private:
	string title;
	string author;
	string isbn;
	string publication;
	User user;
	long date;

public:
	// Constructors
	Book();
	Book(string title, string author, string isbn, string publication);

	// Getters and Setters
	void setTitle(string title);
	void setAuthor(string author);
	void setIsbn(string isbn);
	void setPublication(string publication);
	void setUser(User user);
	void setDate(long date);
	string getTitle();
	string getAuthor();
	string getIsbn();
	string getPublication();
	User getUser();

	// Other Methods
	bool bookRequest(User user);
	long showDueDate();
};
