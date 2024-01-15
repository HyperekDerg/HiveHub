#include "edit_methods.h"

void removeUserFromDatabase(WriteDatabase& writeDatabase, const string& email) {
	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		if (writeDatabase.removeUser(email)) {
			cout << endl << "####################\nUser successfully removed from the database.\n####################" << endl << endl;
			system("PAUSE");
		}
		else {
			cout << endl << "####################\nFailed to remove user. An unexpected error occurred.\n####################" << endl << endl;
			system("PAUSE");
		}
	}
	else {
		cout << endl << "####################\nUser not found in the database. No changes made.\n####################" << endl << endl;
		system("PAUSE");
	}
}

void userRemove(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|REMOVE USER]\n\nTo remove a user from the database, please provide the user's email." << endl << endl;

	string email = getUserEmailForEdit();

	if (email == "abort") {
		displayMessages("abortByUser");
		return;
	}

	toLowerCase(email);
	removeUserFromDatabase(writeDatabase, email);
}