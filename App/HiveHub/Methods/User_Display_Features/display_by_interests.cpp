#include "Display_Features.h"

string getUserInterestsInput() {
	cout << "Enter Interests without spaces! (or type 'abort' to cancel): ";
	string interestsInput;
	getline(cin, interestsInput);
	return interestsInput;
}

void displayByInterests(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|BY INTERESTS]\n\nTo display user data by interests, provide interests separated by commas." << endl << endl;

	string interestsInput = getUserInterestsInput();

	if (interestsInput == "abort") {
		displayMessages("abortByUser");
		return;
	}

	cout << endl;
	vector<string> interests;
	stringstream ss(interestsInput);
	string interest;

	while (getline(ss, interest, ',')) {
		interests.push_back(interest);
	}

	ReadDatabase readDatabase(writeDatabase);
	if (readDatabase.findUsersByInterests(interests, cout)) {
		cout << "Users with the specified interests displayed.\n####################" << endl << endl;
		system("PAUSE");
	}
	else {
		cout << "####################\nNo users found with the specified interests.\n####################" << endl << endl;
		system("PAUSE");
	}
}