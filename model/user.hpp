
#pragma once
#include <string>
using namespace std;

class User
{
private:
	string name;
	string id;
	string password;

public:
	// Constructors
	User();
	User(string name, string password);
	User(string name, string id, string password);

	// Getters and Setters
	void setName(string name);
	void setId(string id);
	void setPassword(string password);
	string getName();
	string getId();
	string getPassword();
};
