#pragma once
#include "model/user.hpp"
#include <vector>

class UserDB
{
private:
	vector<User *> users;

public:
	UserDB();
	void add(User *user);
	bool update(User *user, string name);
	bool remove(string name);
	User *search(string name);
	int authenticate(string name, string password, char type);
	void displayAll();
};

UserDB::UserDB()
{
	users.clear();
}

void UserDB::add(User *user)
{
	users.push_back(user);
}

bool UserDB::update(User *user, string name)
{
	if (user->getName() != name)
	{
		return false;
	}
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName() == name)
		{
			users[i] = user;
			return true;
		}
	}
	return false;
}

bool UserDB::remove(string name)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName() == name)
		{
			users.erase(users.begin() + i);
			return true;
		}
	}
	return false;
}

User *UserDB::search(string name)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName() == name)
		{
			return users[i];
		}
	}
	return new User();
}

int UserDB::authenticate(string name, string password, char type)
{
	for (User *user : users)
	{
		if (user->getName() == name)
		{
			if (user->getPassword() == password)
			{
				if (user->getType() == type)
				{
					return 0;
				}
				else
				{
					cout << "User Not of requested category" << endl;
					return 1;
				}
			}
			else
			{
				cout << "Invalid credentials" << endl;
				return 2;
			}
		}
	}
	cout << "User Not Found" << endl;
	return 3;
}

void UserDB::displayAll()
{
	cout << "Total users: " << users.size() << endl;
	cout << "Name and type of user" << endl;
	for (User *user : users)
	{
		cout << user->getName() << " [" << user->getType() << "]" << endl;
	}
}
