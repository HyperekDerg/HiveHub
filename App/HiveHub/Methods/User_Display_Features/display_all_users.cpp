#include "display_features.h"

void displayEveryone(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|ALL USERS]" << endl << endl;

	const map<string, UserData>& userMap = writeDatabase.getUserMap();

	if (userMap.empty()) {
		cout << "####################\nNo users in the database.\n####################" << endl << endl;
		system("PAUSE");
		return;
	}

	int userCount = 0;

	for (const auto& pair : userMap) {
		const UserData& userData = pair.second;

		if (userCount > 0) {
			cout << "----------------------------------------" << endl;
		}

		cout << "Email: " << userData.email << endl;
		cout << "First Name: " << userData.firstName << endl;
		cout << "Last Name: " << userData.lastName << endl;
		cout << "Address: " << userData.address << endl;
		cout << "Interests: ";
		for (const string& interest : userData.interests) {
			cout << interest << ", ";
		}
		cout << endl;

		userCount++;
	}

	if (userCount > 0) {
		cout << endl << "####################\nTotal users in the database:" << endl;
		cout << userCount;
		cout << endl << "####################" << endl << endl;
		system("PAUSE");
	}
}