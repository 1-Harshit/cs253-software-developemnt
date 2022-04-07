#include "user.hpp"
#include <iostream>

// Constructors
User::User()
{
	this->name = "";
}

User::User(string name, string id, string password)
{
	this->name = name;
	this->id = id;
	this->password = password;
}

User::User(string name, string password)
{
	this->name = name;
	this->id = to_string(time(0)) + to_string(rand() % 100);
	this->password = password;
}

User::User(string name, string password, char type)
{
	this->name = name;
	this->id = to_string(time(0)) + to_string(rand() % 100);
	this->password = password;
	this->type = type;
}

// Getters
string User::getId()
{
	return this->id;
}

string User::getName()
{
	return this->name;
}

string User::getPassword()
{
	return this->password;
}

char User::getType()
{
	return this->type;
}

// Setters
void User::setName(string name)
{
	this->name = name;
}

void User::setId(string id)
{
	this->id = id;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setType(char type)
{
	this->type = type;
}
