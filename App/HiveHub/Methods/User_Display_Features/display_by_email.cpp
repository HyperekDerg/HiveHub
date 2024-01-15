#include "display_features.h"

void displayUserInfo(const UserData& userData) {
	cout << endl << "####################\nUser Information:" << endl;
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

void displayByEmail(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|BY EMAIL]\n\nTo display user data, please provide the user's email." << endl << endl;

	string email = getUserEmailForEdit();

	if (email == "abort") {
		displayMessages("abortByUser");
		return;
	}

	toLowerCase(email);

	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		UserData userData = readDatabase.getUser(email);
		displayUserInfo(userData);
	}
	else {
		cout << endl << "####################\nUser not found in the database. No information to display.\n####################" << endl << endl;
		system("PAUSE");
	}
}