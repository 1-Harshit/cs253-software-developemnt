#include "professor.hpp"

Professor::Professor() : User()
{
	this->fine = 0;
}

Professor::Professor(string name, string password) : User(name, password)
{
	fine = 0;
	books.clear();
}
