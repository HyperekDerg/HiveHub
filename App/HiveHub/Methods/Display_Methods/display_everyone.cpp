#include "display_methods.h"

void displayEveryone(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|ALL USERS]" << endl << endl;

	const map<string, UserData>& userMap = writeDatabase.getUserMap();

	if (userMap.empty()) {
		cout << "####################" << endl;
		cout << "No users in the database." << endl;
		cout << "####################" << endl << endl;
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
		cout << endl << "####################" << endl;
		cout << "Total users in the database: " << userCount;
		cout << endl << "####################" << endl << endl;
		system("PAUSE");
	}
}
