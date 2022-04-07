#include <iostream>

#include "bookDB.hpp"
#include "userDB.hpp"

#include "model/librarian.hpp"
#include "model/student.hpp"
#include "model/professor.hpp"

using namespace std;

#define HASH "#######"
#define OPTION HASH "Choose an option" HASH

void init(UserDB *userDB, BookDB *bookDB)
{
	Librarian *librarian = new Librarian("lib", "libpass");
	userDB->add(librarian);

	Book book = Book("A Clash of Kings", "GRR Martin", "199100", "Voyager");
	bookDB->add(book);
	book = Book("A Storm of Swords", "GRR Martin", "200000", "Bantam Spectra");
	bookDB->add(book);
	book = Book("A Feast for Crows", "GRR Martin", "200500", "Bantam Spectra");
	bookDB->add(book);
}

Book createBook()
{
	cout << "Enter details about the new book" << endl;

	string title, author, isbn, publisher;
	cout << "Title: ";
	getline(cin, title);
	getline(cin, title);
	cout << "Author: ";
	getline(cin, author);
	cout << "ISBN: ";
	getline(cin, isbn);
	cout << "Publisher: ";
	getline(cin, publisher);

	return Book(title, author, isbn, publisher);
}

Book searchBook()
{
	cout << OPTION << endl;
	cout << "1. Search using title" << endl;
	cout << "2. Search using author" << endl;
	cout << "3. Search using ISBN" << endl;
	cout << "4. Search using publisher" << endl;
	cout << "Enter your choice: ";
	int option;
	cin >> option;

	string s;
	switch (option)
	{
	case 1:
		cout << "Title: ";
		cin >> s;
		return Book(s, "", "", "");
		break;
	case 2:
		cout << "Author: ";
		cin >> s;
		return Book("", s, "", "");
		break;
	case 3:
		cout << "ISBN: ";
		cin >> s;
		return Book("", "", s, "");
		break;
	case 4:
		cout << "Publisher: ";
		cin >> s;
		return Book("", "", "", s);
		break;
	default:
		cout << "Invalid option" << endl;
		return searchBook();
		break;
	}
}

string getISBN()
{
	string s;
	cout << "Enter ISBN of the book: ";
	cin >> s;
	return s;
}

User *createUser()
{
	cout << "Enter details about the new User no whitespace allowed" << endl;

	string username, password, isbn;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "type [1 for Student and 2 for Professors]: ";
	int option;
	cin >> option;
	switch (option)
	{
	case 1:
		return new Student(username, password);
		break;
	case 2:
		return new Professor(username, password);
		break;
	default:
		cout << "Invalid option" << endl;
		return createUser();
		break;
	}
}

string getName()
{
	string s;
	cout << "Enter username of the user: ";
	cin >> s;
	return s;
}

void librarian(UserDB *userDB, BookDB *bookDB)
{
	cout << HASH "Login as librarian" HASH << endl;
	string username;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		string password;
		cin >> password;
		int res = userDB->authenticate(username, password, 'l');
		if (res == 0)
		{
			cout << "Welcome " << username << endl;
			break;
		}
	}
	int option = -1;
	while (option != 0)
	{
		cout << "Librarian: " << username << endl;
		cout << OPTION << endl;
		cout << "1. Add a book" << endl;
		cout << "2. Remove a book" << endl;
		cout << "3. Search for a book" << endl;
		cout << "4. Modify a book" << endl;
		cout << "5. Add a user" << endl;
		cout << "6. Remove a user" << endl;
		cout << "7. Search for a user" << endl;
		cout << "8. Modify a user" << endl;
		cout << "9. List all users" << endl;
		cout << "10. List all books" << endl;
		cout << "0. Logout" << endl;
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			bookDB->add(createBook());
			break;
		case 2:
			cout << "Deleting a book" << endl;
			bookDB->remove(getISBN());
			break;
		case 3:
			for (Book book : bookDB->search(searchBook()))
			{
				cout << HASH << endl;
				book.display();
			}
			break;
		case 4:
			cout << "Updating a book" << endl;
			bookDB->update(searchBook(), getISBN());
			break;
		case 5:
			userDB->add(createUser());
			break;
		case 6:
			cout << "Deleting a user" << endl;
			userDB->remove(getName());
			break;
		case 7:
			userDB->search(getName());
			break;
		case 8:
			cout << "Updating a user" << endl;
			userDB->update(createUser(), getName());
			break;
		case 9:
			userDB->displayAll();
			break;
		case 10:
			bookDB->displayAll();
			break;
		case 0:
			cout << "Logging out..." << endl;
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}

void student(UserDB *userDB, BookDB *bookDB)
{
	cout << HASH "Login as Student" HASH << endl;
	string username;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		string password;
		cin >> password;
		int res = userDB->authenticate(username, password, 's');
		if (res == 0)
		{
			cout << "Welcome " << username << endl;
			break;
		}
	}
	Student *student = (Student *)userDB->search(username);
	int option = -1;
	string isbn;
	while (option != 0)
	{
		cout << "Student: " << username << endl;
		cout << OPTION << endl;
		cout << "1. View all books" << endl;
		cout << "2. List books" << endl;
		cout << "3. View Dues" << endl;
		cout << "4. Issue a book" << endl;
		cout << "0. Logout" << endl;
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			bookDB->displayAll();
			break;
		case 2:
			student->getBooks();
			break;
		case 3:
			cout << "dues: " << student->calculateFine() << endl;
			break;
		case 4:
			cout << "Issuing a book based on isbn" << endl;
			if (student->getBookCount() > 5)
			{
				cout << "Book issue limit reached" << endl;
			}
			else
			{
				isbn = getISBN();
				Book *book = bookDB->requestBook((User *)student, isbn, time(0) + (30 * 24 * 60 * 60));
				if (book == NULL)
					cout << "No Book Found or not available" << endl;
				else
					student->issue(book);
			}
			break;
		case 0:
			cout << "Logging out ..." << endl;
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}

void professor(UserDB *userDB, BookDB *bookDB)
{
	cout << HASH "Login as Professor" HASH << endl;
	string username;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		string password;
		cin >> password;
		int res = userDB->authenticate(username, password, 'p');
		if (res == 0)
		{
			cout << "Welcome " << username << endl;
			break;
		}
	}
	Professor *professor = (Professor *)userDB->search(username);
	int option = -1;
	while (option != 0)
	{
		cout << "Professor: " << username << endl;
		cout << OPTION << endl;
		cout << "1. View all books" << endl;
		cout << "2. List books" << endl;
		cout << "3. View Dues" << endl;
		cout << "4. Issue a book" << endl;
		cout << "0. Logout" << endl;
		cout << "Enter your option: ";
		cin >> option;
		string isbn;

		switch (option)
		{
		case 1:
			bookDB->displayAll();
			break;
		case 2:
			professor->getBooks();
			break;
		case 3:
			cout << "dues: " << professor->calculateFine() << endl;
			break;
		case 4:
			cout << "Issuing a book based on isbn" << endl;
			isbn = getISBN();
			Book *book = bookDB->requestBook((User *)professor, isbn, time(0) + (60 * 24 * 60 * 60));
			if (book == NULL)
				cout << "No Book Found or not available" << endl;
			else
				professor->issue(book);
			break;
		case 0:
			cout << "Logging out ..." << endl;
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
}
