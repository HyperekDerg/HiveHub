#include "user_interface.h"

UserInterface::UserInterface(const string& title, WriteDatabase& writeDatabase)
	: title(title), writeDatabase(writeDatabase) {}

void UserInterface::display() const {
	cout << "[MAIN MENU]" << endl << endl;
	cout << "=== " << title << " ===" << endl;
	cout << "1. Add New Person" << endl;
	cout << "2. Edit Data" << endl;
	cout << "3. Display People" << endl;
	cout << "4. Exit" << endl << endl;
}

int UserInterface::getUserChoice() const {
	int choice;
	cout << "Enter your choice (1-4): ";
	cin >> choice;
	return choice;
}