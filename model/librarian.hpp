#pragma once

#include "user.hpp"

class Librarian : public User
{
private:
public:
	Librarian();
	Librarian(string name, string password);
};

Librarian::Librarian(/* args */) : User()
{
}

Librarian::Librarian(string name, string password) : User(name, password, 'l')
{
}
