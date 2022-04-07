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
