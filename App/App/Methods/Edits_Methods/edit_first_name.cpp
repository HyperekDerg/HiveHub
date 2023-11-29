#include "edit_methods.h"

void editFirstName(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|FIRST_NAME]" << endl << endl;
	cout << "To edit the first name of a user in the database, please provide the user's email" << endl << endl;

	string email;

	cout << "Enter Email: ";
	getline(cin, email);

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
			cout << endl << "####################" << endl;
			cout << "First Name updated successfully." << endl;
			cout << "####################" << endl;
		}
		else {
			cout << endl << "####################" << endl;
			cout << "No changes made. Keeping existing First Name." << endl;
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