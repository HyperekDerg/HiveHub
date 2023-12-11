#include "display_methods.h"

void displayByEmail(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|BY EMAIL]" << endl << endl;
	cout << "To display user data. Provide user email." << endl << endl;

	string email;

	cout << "Enter Email (or type 'abort' to cancel) : ";
	getline(cin, email);

	if (email == "abort") {
		cout << endl << "####################" << endl;
		cout << "Operation aborted by user." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
		return;
	}

	toLowerCase(email);

	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		UserData userData = readDatabase.getUser(email);

		cout << endl << "####################" << endl;
		cout << "First Name: " << userData.firstName << endl;
		cout << "Last Name: " << userData.lastName << endl;
		cout << "Address: " << userData.address << endl;
		cout << "Email: " << userData.email << endl;
		cout << "Interests: ";
		for (const string& interest : userData.interests) {
			cout << interest << ", ";
		}
		cout << endl << "####################" << endl << endl;
		system("PAUSE");
	}
	else {
		cout << endl << "####################" << endl;
		cout << "User not found in the database. No changes made." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
	}
}