#include "helper.cpp"

using namespace std;

#define HASH "#######"
#define OPTION HASH "Choose an option" HASH

int main()
{
	cout << "Welcome to Library Management System CLI!" << endl;
	BookDB *bookDB = new BookDB();
	UserDB *userDB = new UserDB();

	init(userDB, bookDB);

	int option = 0;
	while (option != 4)
	{
		cout << OPTION << endl;
		cout << "1. Login as Librarian" << endl;
		cout << "2. Login as Student" << endl;
		cout << "3. Login as Professor" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			librarian(userDB, bookDB);
			break;
		case 2:
			cout << "Student" << endl;
			break;
		case 3:
			cout << "Professor" << endl;
			break;
		case 4:
			cout << "Exiting" << endl;
			break;
		default:
			cout << "Invalid option!" << endl;
			break;
		}
	}
}