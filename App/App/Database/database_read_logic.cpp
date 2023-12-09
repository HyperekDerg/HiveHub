#include "database_controller.h"

ReadDatabase::ReadDatabase(const WriteDatabase& writeDatabase) : writeDatabase_(writeDatabase) {}

void ReadDatabase::displayUser(const UserData& userData, ostream& output) {
	output << "Email: " << userData.email << endl;
	output << "First Name: " << userData.firstName << endl;
	output << "Last Name: " << userData.lastName << endl;
	output << "Address: " << userData.address << endl;
	output << "Interests: ";
	for (const string& interest : userData.interests) {
		output << interest << ", ";
	}
	output << endl;
}


bool ReadDatabase::findUserByEmail(const string& email) {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	auto it = userMap.find(email);

	return it != userMap.end();
}

UserData ReadDatabase::getUser(const string& email) const {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	auto it = userMap.find(email);
	if (it != userMap.end()) {
		return it->second;
	}
	return UserData{};
}
bool ReadDatabase::findUsersByInterests(const vector<string>& interests, ostream& output) {
	const map<string, UserData>& userMap = writeDatabase_.getUserMap();
	bool found = false;
	int userCount = 0;

	output << "Interests provided: ";
	for (const auto& interest : interests) {
		output << interest << ", ";
	}
	output << endl;

	for (const auto& pair : userMap) {
		const UserData& userData = pair.second;

		bool hasInterests = true;

		if (userData.interests.empty()) {
			hasInterests = false;
		}
		else {
			for (const string& interest : interests) {
				if (find(userData.interests.begin(), userData.interests.end(), interest) == userData.interests.end()) {
					hasInterests = false;
					break;
				}
			}
		}

		if (hasInterests) {
			if (found) {
				output << "----------------------------------------" << endl;
			}
			displayUser(userData, output);
			found = true;
			userCount++;
		}
	}

	if (found) {
		output << "Total users found with the specified interests: " << userCount << endl;
	}
	else {
		output << "No users found with the specified interests." << endl;
	}

	return found;
}