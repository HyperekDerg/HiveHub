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

UserData ReadDatabase::getUser(const string& email) const {
	auto it = userMap.find(email);
	if (it != userMap.end()) {
		return it->second;
	}
	return UserData{};
}

bool ReadDatabase::findUsersByInterests(const vector<string>& interests) {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	bool found = false;

	for (const auto& pair : userMap) {
		const UserData& userData = pair.second;

		bool hasInterests = true;

		UserData parsedUserData;
		if (LineParser::parseLine(userData.email + "," + userData.firstName + "," +
			userData.lastName + "," + userData.address, parsedUserData)) {
			for (const string& interest : interests) {
				if (find(parsedUserData.interests.begin(), parsedUserData.interests.end(), interest) ==
					parsedUserData.interests.end()) {
					hasInterests = false;
					break;
				}
			}
		}
		else {
			cerr << "Error parsing user data for email: " << userData.email << endl;
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