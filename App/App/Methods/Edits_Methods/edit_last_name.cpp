#include "edit_methods.h"

void editLastName(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|LAST_NAME]" << endl << endl;
	cout << "To edit the last name of a user in the database, please provide the user's email" << endl << endl;

	string email;

	cout << "Enter Email (or type 'abort' to cancel) : ";
	getline(cin, email);

	if (email == "abort") {
		cout << endl << "####################" << endl;
		cout << "Operation aborted by user." << endl;
		cout << "####################" << endl;
		system("PAUSE");
		return;
	}

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
			cout << endl << "####################" << endl;
			cout << "Last Name updated successfully." << endl;
			cout << "####################" << endl;
		}
		else {
			cout << endl << "####################" << endl;
			cout << "No changes made. Keeping existing Last Name." << endl;
			cout << "####################" << endl;
		}

		system("PAUSE");
	}
	else {
		cout << endl << "####################" << endl;
		cout << "User not found in the database. No changes made." << endl;
		cout << "####################" << endl;
		system("PAUSE");
	}
}