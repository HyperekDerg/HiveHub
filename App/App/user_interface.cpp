#include "user_interface.h"

UserInterface::UserInterface(const string& title, WriteDatabase& writeDatabase)
	: title(title), writeDatabase(writeDatabase) {}

void UserInterface::display() const {
	cout << "[MAIN]" << endl << endl;
	cout << "=== " << title << " ===" << endl;
	cout << "1. Add New Person" << endl;
	cout << "2. Edit Data" << endl;
	cout << "3. Display/Group People" << endl;
	cout << "4. End Task [EXIT]" << endl;
}

int UserInterface::getUserChoice() const {
	int choice;
	cout << "Choose an option (1-4): ";
	cin >> choice;
	return choice;
}

void UserInterface::runUserChoice() const {
	switch (int choice = getUserChoice(); choice) {
	case 1: {
		system("CLS");
		userCreator(writeDatabase);
		system("CLS");
		break;
	}
	case 2: {
		system("CLS");
		EditTool editTool(writeDatabase);
		editTool.runUserChoice();
		system("CLS");
		break;
	}
	case 3: {
		system("CLS");
		DisplayTool displayTool(writeDatabase);
		displayTool.runUserChoice();
		system("CLS");
		break; 
	}
	case 4:
		cout << "Exiting the program." << endl;
		exit(0); // Exit the program
	default:
		system("CLS");
		cout << "Invalid choice." << endl;
		system("PAUSE");
		system("CLS");
	}
}
