
#pragma once
#include <string>
using namespace std;

class User
{
private:
	string name;
	string id;
	string password;
	char type;

public:
	// Constructors
	User();
	User(string name, string password);
	User(string name, string id, string password);
	User(string name, string password, char type);

	// Getters and Setters
	void setName(string name);
	void setId(string id);
	void setPassword(string password);
	void setType(char type);
	string getName();
	string getId();
	string getPassword();
	char getType();
};
