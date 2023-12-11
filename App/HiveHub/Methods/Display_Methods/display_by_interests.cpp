#include "display_methods.h"

void displayByInterests(WriteDatabase& writeDatabase) {
	cout << "[MAIN|DISPLAY|BY INTERESTS]" << endl << endl;
	cout << "To display user data by interests. Provide interests separated by commas." << endl << endl;

	string interestsInput;

	cout << "Enter Interests without space! (or type 'abort' to cancel): ";
	getline(cin, interestsInput);

	if (interestsInput == "abort") {
		cout << endl << "####################" << endl;
		cout << "Operation aborted by user." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
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

		cout << "Users with the specified interests displayed." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
	}
	else {
		cout << endl << "####################" << endl;
		cout << "No users found with the specified interests." << endl;
		cout << "####################" << endl << endl;
		system("PAUSE");
	}
}
