#include "edit_methods.h"

void editUserFirstName(WriteDatabase& writeDatabase, const string& email) {
	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		UserData userData = readDatabase.getUser(email);

		cout << "Current First Name: " << userData.firstName << endl;

		cout << "Enter the new First Name (or press Enter to keep existing): ";
		string newFirstName;
		getline(cin, newFirstName);

		if (!newFirstName.empty()) {
			userData.firstName = newFirstName;
			writeDatabase.updateUser(email, userData);
			cout << endl << "####################\nFirst Name updated successfully.\n####################" << endl << endl;
		}
		else {
			cout << endl << "####################\nNo changes made. Keeping existing Last Name.\n####################" << endl << endl;
		}

		system("PAUSE");
	}
	else {
		cout << endl << "####################\nUser not found in the database. No changes made.\n####################" << endl << endl;
		system("PAUSE");
	}
}

void editFirstName(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|FIRST_NAME]\nTo edit the first name of a user in the database, please provide the user's email." << endl << endl;

	string email = getUserEmailForEdit();

	if (email == "abort") {
		displayMessages("abortByUser");
		return;
	}

	toLowerCase(email);
	editUserFirstName(writeDatabase, email);
}