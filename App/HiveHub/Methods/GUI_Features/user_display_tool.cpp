#include "user_interface.h"

UserDisplay::UserDisplay(WriteDatabase& writeDatabase)
	: writeDatabase(writeDatabase) {}

void UserDisplay::menu() const {
	system("CLS");
	cout << "[MAIN|USER DISPLAY]" << endl << endl;
	cout << "Welcome to the User Display tool. Here, you can check and display records.\n";
	cout << "Before you start, please select which operation you want to do.\n\n";

	cout << "===  User Display  ===" << endl;
	cout << "1. Display user by email" << endl;
	cout << "2. Display users by interests" << endl;
	cout << "3. Display everyone" << endl;
	cout << "4. Go back to the Main Menu" << endl << endl;
}

int UserDisplay::getUserChoice() const {
	int choice;
	while (true) {
		cout << "Choose an option (1-4): ";
		if (cin >> choice && choice >= 1 && choice <= 4) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else {
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return choice;
}

void UserDisplay::runUserChoice() const {
	int choice = 0;
	do {
		if (choice != 4) {
			menu();
		}
		choice = getUserChoice();
		switch (choice) {
		case 1:
		{
			system("CLS");
			displayByEmail(writeDatabase);
			system("CLS");
			break;
		}
		case 2:
		{
			system("CLS");
			displayByInterests(writeDatabase);
			system("CLS");
			break;
		}
		case 3:
		{
			system("CLS");
			displayEveryone(writeDatabase);
			system("CLS");
			break;
		}
		break;
		case 4:
			cout << "Going back to the Main Menu." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
		}
	} while (choice != 4);
}