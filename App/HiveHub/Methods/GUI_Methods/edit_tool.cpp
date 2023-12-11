#include "user_interface.h"

EditTool::EditTool(WriteDatabase& writeDatabase)
	: writeDatabase(writeDatabase) {}

void EditTool::menu() const {
	cout << "[MAIN|EDIT]" << endl << endl;
	cout << "Welcome to the Edit tool. Here, you can delete users or update database records.\n";
	cout << "Before you start, please select which operation you want to do.\n\n";

	cout << "===  Edit Tool  ===" << endl;
	cout << "1. Remove user" << endl;
	cout << "2. Edit First Name" << endl;
	cout << "3. Edit Last Name" << endl;
	cout << "4. Manage Interests" << endl;
	cout << "5. Go back to the Main Menu" << endl << endl;
}

int EditTool::getUserChoice() const {
	int choice;
	while (true) {
		cout << "Choose an option (1-5): ";
		if (cin >> choice && choice >= 1 && choice <= 5) {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		else {
			cout << "Invalid input. Please enter a number between 1 and 5." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	return choice;
}

void EditTool::runUserChoice() const {
	int choice = 0;
	do {
		if (choice != 5) {
			menu();
		}
		choice = getUserChoice();
		switch (choice) {
		case 1:
			system("CLS");
			userRemove(writeDatabase);
			system("CLS");
			break;
		case 2:
			system("CLS");
			editFirstName(writeDatabase);
			system("CLS");
			break;
		case 3:
			system("CLS");
			editLastName(writeDatabase);
			system("CLS");
			break;
		case 4:
			system("CLS");
			editInterests(writeDatabase);
			system("CLS");
			break;
		case 5:
			cout << "Going back to the Main Menu." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
		}
	} while (choice != 5);
}
