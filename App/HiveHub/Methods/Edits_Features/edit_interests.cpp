#include "edit_methods.h"

void editUserInterests(WriteDatabase& writeDatabase, const string& email) {
	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUserByEmail(email)) {
		UserData userData = readDatabase.getUser(email);

		cout << "Current Interests: ";
		for (const string& interest : userData.interests) {
			cout << interest << ", ";
		}

		cout << endl << "Enter the new interests (comma-separated, press Enter to keep existing): ";
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

			cout << endl << "####################\nInterests updated successfully.\n###################" << endl << endl;
		}
		else {
			cout << endl << "####################\nNo changes made. Keeping existing interests.\n###################" << endl << endl;
		}
	}
	else {
		cout << endl << "####################\nUser not found in the database. No changes made.\n###################" << endl << endl;
	}

	system("PAUSE");
}

void editInterests(WriteDatabase& writeDatabase) {
	cout << "[MAIN|EDIT|INTERESTS]\n\nTo edit the interests of a user in the database, please provide the user's email." << endl << endl;

	string email = getUserEmailForEdit();

	if (email == "abort") {
		displayMessages("abortByUser");
		return;
	}

	toLowerCase(email);
	editUserInterests(writeDatabase, email);
}