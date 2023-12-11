#include "user_interface.h"

DisplayTool::DisplayTool(WriteDatabase& writeDatabase)
	: writeDatabase(writeDatabase) {}

void DisplayTool::menu() const {
	cout << "[MAIN|DISPLAY]" << endl << endl;
	cout << "Welcome to the Display tool. Here, you can check and display records.\n";
	cout << "Before you start, please select which operation you want to do.\n\n";

	cout << "===  Edit Tool  ===" << endl;
	cout << "1. Display user by email" << endl;
	cout << "2. Display users by interests" << endl;
	cout << "3. Display everyone" << endl;
	cout << "4. Go back to the Main Menu" << endl << endl;
}

int DisplayTool::getUserChoice() const {
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

void DisplayTool::runUserChoice() const {
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
