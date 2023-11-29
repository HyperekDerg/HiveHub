#include "edit_methods.h"

void userRemove(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|REMOVE]" << endl << endl;
	cout << "To remove user data from the database, please provide the user's email" << endl << endl;

	string email;

	cout << "Enter Email: ";
	cin >> email;
	cin.ignore();

	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		if (writeDatabase.removeUser(email)) {
			cout << endl << "####################" << endl;
			cout << "User removed successfully." << endl;
			cout << "####################" << endl;
			system("PAUSE");
		}
		else {
			cout << endl << "####################" << endl;
			cout << "Failed to remove user. Unexpected error occurred." << endl;
			cout << "####################" << endl;
			system("PAUSE");
		}
	}
	else {
		cout << endl << "####################" << endl;
		cout << "User not found in the database. No changes made." << endl;
		cout << "####################" << endl;
		system("PAUSE");
	}
}
