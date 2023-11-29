#include "database_controller.h"

bool LineParser::parseLine(const string& line, UserData& userData) {
	istringstream iss(line);
	string email, firstName, lastName, address, interestsString;
	char delimiter = ',';

	getline(iss, email, delimiter);
	getline(iss, firstName, delimiter);
	getline(iss, lastName, delimiter);
	getline(iss, address, delimiter);
	getline(iss, interestsString);

	stringstream interestsStream(interestsString);
	vector<string> interests;
	string interest;
	while (getline(interestsStream, interest, ',')) {
		interests.push_back(interest);
	}

	userData.email = email;
	userData.firstName = firstName;
	userData.lastName = lastName;
	userData.address = address;
	userData.interests = interests;

	return !email.empty();
}