#include "database_controller.h"

bool LineParser::parseLine(const string& line, UserData& userData) {
	istringstream iss(line);
	string email, firstName, lastName, address;
	vector<string> interests;
	char delimiter = ',';
	getline(iss, email, delimiter);
	getline(iss, firstName, delimiter);
	getline(iss, lastName, delimiter);
	getline(iss, address, delimiter);

	string interest;
	while (getline(iss, interest, delimiter)) {
		interests.push_back(interest);
	}

	userData.email = email;
	userData.firstName = firstName;
	userData.lastName = lastName;
	userData.address = address;
	userData.interests = interests;

	return !email.empty();
}