#include "edit_methods.h"

void editInterests(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|INTERESTS]" << endl << endl;
	cout << "To edit the interests of a user in the database, please provide the user's email" << endl << endl;

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

		cout << "Current Interests: ";
		for (const string& interest : userData.interests) {
			cout << interest << ", ";
		}

		cout << endl << "Enter the new interests (comma-separated, enter to keep existing): ";
		string interestsInput;
		getline(cin, interestsInput);

		if (!interestsInput.empty()) {
			vector<string> newInterests;
			stringstream ss(interestsInput);
			string interest;
			while (getline(ss, interest, ',')) {
				newInterests.push_back(interest);
			}

			userData.interests = newInterests;
			writeDatabase.updateUser(email, userData);

			cout << endl << "####################" << endl;
			cout << "Interests updated successfully." << endl;
			cout << "####################" << endl;
		}
		else {
			cout << endl << "####################" << endl;
			cout << "No changes made. Keeping existing interests." << endl;
			cout << "####################" << endl;
		}
	}
	else {
		cout << endl << "####################" << endl;
		cout << "User not found in the database. No changes made." << endl;
		cout << "####################" << endl;
	}

	system("PAUSE");
}