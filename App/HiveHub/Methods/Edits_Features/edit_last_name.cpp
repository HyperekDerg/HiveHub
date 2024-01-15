#include "edit_methods.h"

void editUserLastName(WriteDatabase& writeDatabase, const string& email) {
	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		UserData userData = readDatabase.getUser(email);

		cout << "Current Last Name: " << userData.lastName << endl;

		cout << "Enter the new Last Name (or press Enter to keep existing): ";
		string newLastName;
		getline(cin, newLastName);

		if (!newLastName.empty()) {
			userData.lastName = newLastName;
			writeDatabase.updateUser(email, userData);
			cout << endl << "####################\nLast Name updated successfully.\n####################" << endl << endl;
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

void editLastName(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|LAST_NAME]\n\nTo edit the last name of a user in the database, please provide the user's email." << endl << endl;

	string email = getUserEmailForEdit();

	if (email == "abort") {
		displayMessages("abortByUser");
		return;
	}

	toLowerCase(email);
	editUserLastName(writeDatabase, email);
}