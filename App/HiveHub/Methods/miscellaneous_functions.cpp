#include "methods.h"

void toUpperCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void toLowerCase(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

string getUserEmailForEdit() {
	cout << "Enter Email (or type 'abort' to cancel): ";
	string email;
	getline(cin, email);
	return email;
}

void displayMessages(const string& str) {
	if (str == "invalidChoice") {
		cout << "Error: Invalid choice." << endl;
		system("PAUSE");
	}
	else if (str == "databaseError") {
		cout << "Error: Failed to load the database. Exiting the program." << endl;
	}
	else if (str == "exitProgram") {
		cout << endl << "#################### \nExiting the program. Goodbye!\n####################" << endl << endl;

	}
	else if (str == "abortByUser") {
		cout << endl << "####################\nOperation aborted by user.\n####################" << endl << endl;
		system("PAUSE");
	}
	else {
		cerr << "Unknown message type." << endl;
	}
}

void setParams(const string &selectedColor, bool &exitProgram) {
	setConsoleColor(selectedColor);
	exitProgram = false;
}