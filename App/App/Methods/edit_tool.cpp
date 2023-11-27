#include "edit_tool.h"

EditTool::EditTool(WriteDatabase& writeDatabase)
	: writeDatabase(writeDatabase) {}

void EditTool::menu() const {
	cout << "[MAIN|EDIT]" << endl << endl;
	cout << "Welcome to the Edit tool. Inside this tool, you can remove a user from the database or change values of database records.\n";
	cout << "Before you start, please select which operation you want to do.\n\n";

	cout << "===  Edit Tool  ===" << endl;
	cout << "1. Remove user" << endl;
	cout << "2. Edit First Name" << endl;
	cout << "3. Edit Last Name" << endl;
	cout << "4. Go back to the Main Menu" << endl;
}

int EditTool::getUserChoice() const {
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

void EditTool::runUserChoice() const {
	int choice = 0;
	do {
		if (choice != 4) {
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
			// Call the subroutine for Option 2
			break;
		case 3:
			// Call the subroutine for Option 3
			break;
		case 4:
			cout << "Going back to the Main Menu." << endl;
			break;
		default:
			cout << "Invalid choice." << endl;
		}
	} while (choice != 4);
}
