#include "methods.h"

void userCreator(WriteDatabase& writeDatabase) {
	cout << "[MAIN|CREATION]" << endl << endl;
	cout << "Welcome to the user Creation Tool. This tool allows you to add a new person to the database." << endl;
	cout << "Please prepare data in the following format: [Email | FirstName | LastName | Address | Interests]" << endl << endl;

	string email, firstName, lastName, address, interestInput;
	vector<string> interests;

	cout << "Enter Email (or type 'abort' to cancel): ";
	cin >> email;

	if (email == "abort") {
		cout << endl << "####################" << endl;
		cout << "Operation aborted by user." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
		return;
	}
	cin.ignore();

	cout << "Enter First Name: ";
	getline(cin, firstName);

	cout << "Enter Last Name: ";
	getline(cin, lastName);

	cout << "Enter Address: ";
	getline(cin, address);

	cout << "Enter Interests (comma-separated without space): ";
	getline(cin, interestInput);

	istringstream iss(interestInput);
	string interest;
	while (getline(iss, interest, ',')) {
		interests.push_back(interest);
	}

	toLowerCase(email);

	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		cout << endl << "####################" << endl;
		cout << "ERROR:. This email already exists in the database! Please provide an email that doesn't exist." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
	}
	else {
		writeDatabase.addUser(email, firstName, lastName, address, interests);
		cout << endl << "####################" << endl;
		cout << "SUCCESS:. User added to the database successfully." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
	}
}