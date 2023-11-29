#include "database_controller.h"

WriteDatabase::WriteDatabase(const string& filename) : filename_(filename) {
	load();
}

WriteDatabase::~WriteDatabase() {
	save();
}

void WriteDatabase::addUser(const string& email, const string& firstName, const string& lastName, const string& address, const vector<string>& interests) {
	UserData userData;
	userData.email = email;
	userData.firstName = firstName;
	userData.lastName = lastName;
	userData.address = address;
	userData.interests = interests;
	userMap[email] = userData;
	save();
}

bool WriteDatabase::removeUser(const string& email) {
	auto it = userMap.find(email);
	if (it != userMap.end()) {
		userMap.erase(it);
		save();
		return true;
	}
	return false;
}

UserData WriteDatabase::getUser(const string& email) const {
	auto it = userMap.find(email);
	if (it != userMap.end()) {
		return it->second;
	}
	return UserData{};
}

bool WriteDatabase::updateUser(const string& email, const UserData& updatedUserData) {
	auto it = userMap.find(email);
	if (it != userMap.end()) {
		userMap[email] = updatedUserData;
		save();
		return true;
	}
	return false;
}

bool WriteDatabase::load() {
	ifstream file(filename_);
	if (!file.is_open()) {
		return false;
	}

	string line;
	while (getline(file, line)) {
		UserData userData;
		if (LineParser::parseLine(line, userData)) {
			userMap[userData.email] = userData;
		}
	}

	file.close();
	return true;
}

bool WriteDatabase::save() {
	ofstream file(filename_);
	if (!file.is_open()) {
		return false;
	}

	for (const auto& pair : userMap) {
		const UserData& userData = pair.second;
		file << userData.email << ","
			<< userData.firstName << ","
			<< userData.lastName << ","
			<< userData.address << ",";

		for (size_t i = 0; i < userData.interests.size(); ++i) {
			file << userData.interests[i];
			if (i < userData.interests.size() - 1) {
				file << ",";
			}
		}

		file << endl;
	}

	file.close();
	return true;
}