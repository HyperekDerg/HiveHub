#include "methods.h"

void inputUserData(string& email, string& firstName, string& lastName, string& address, string& interestInput, vector<string>& interests, bool& addNewUser) {
	cout << "Enter Email (or type 'abort' to cancel): ";
	cin >> email;

	if (email == "abort") {
		displayMessages("abortByUser");
		addNewUser = false;
		return;
	}
	cin.ignore();

	cout << "Enter First Name: ";
	getline(cin, firstName);

	cout << "Enter Last Name: ";
	getline(cin, lastName);

	cout << "Enter Address: ";
	getline(cin, address);

	cout << "Enter Interests (comma-separated without spaces): ";
	getline(cin, interestInput);

	istringstream iss(interestInput);
	string interest;
	interests.clear();
	while (getline(iss, interest, ',')) {
		interests.push_back(interest);
	}
}

void userCreator(WriteDatabase& writeDatabase) {
	system("CLS");
	cout << "[MAIN|CREATION] \n\nWelcome to the User Creation Tool. This tool allows you to add a new person to the database.\nPlease enter the required information in the following format: [Email | FirstName | LastName | Address | Interests]" << endl << endl;

	string email, firstName, lastName, address, interestInput;
	vector<string> interests;
	bool addNewUser = true;

	while (addNewUser) {
		inputUserData(email, firstName, lastName, address, interestInput, interests, addNewUser);
		toLowerCase(email);

		if (!addNewUser) {
			break;
		}

		ReadDatabase readDatabase(writeDatabase);
		if (readDatabase.findUserByEmail(email)) {
			cout << endl << "####################\nError: This email already exists in the database! Please provide a unique email.\n####################" << endl << endl;
		}
		else {
			writeDatabase.addUser(email, firstName, lastName, address, interests);
			cout << endl << "####################\nSuccess: User added to the database successfully.\n####################" << endl << endl;
		}
	}
}