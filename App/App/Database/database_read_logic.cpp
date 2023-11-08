#include "database_controller.h"

ReadDatabase::ReadDatabase(const WriteDatabase& writeDatabase) : writeDatabase_(writeDatabase) {}

void ReadDatabase::displayUser(const UserData& userData) {
	cout << "Email: " << userData.email << endl;
	cout << "First Name: " << userData.firstName << endl;
	cout << "Last Name: " << userData.lastName << endl;
	cout << "Address: " << userData.address << endl;
	cout << "Interests: ";
	for (const string& interest : userData.interests) {
		cout << interest << ", ";
	}
	cout << endl;
}

bool ReadDatabase::findUserByEmail(const string& email) {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	auto it = userMap.find(email);

	return it != userMap.end();
}

bool ReadDatabase::findUsersByInterests(const vector<string>& interests) {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	bool found = false;
	LineParser lineParser;

	for (const auto& pair : userMap) {
		const UserData& userData = pair.second;

		bool hasInterests = true;

		// Check if the interests provided by the user are a subset of the user's interests
		for (const string& interest : interests) {
			if (find(userData.interests.begin(), userData.interests.end(), interest) == userData.interests.end()) {
				hasInterests = false;
				break;
			}
		}

		if (hasInterests) {
			displayUser(userData);
			found = true;
		}
	}

	if (!found) {
		cout << "No users found with the specified interests." << endl;
	}

	return found;
}