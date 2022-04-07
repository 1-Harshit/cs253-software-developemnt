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
