#include "config.h"

void checkOrCreateDatabaseFile(const string& filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		cout << "Database file not found. Do you want to create a new one? (Y/n): ";
		char response;
		cin >> response;

		if (response == 'y' || response == 'Y') {
			ofstream newFile(filename);
			if (!newFile.is_open()) {
				cerr << "Error creating the database file. Exiting the application." << endl;
				exit(EXIT_FAILURE);
			}

			cout << "New database file created successfully." << endl;
			system("PAUSE");
			system("cls");
		}
		else {
			cerr << "Database file not created. Exiting the application." << endl;
			exit(EXIT_FAILURE);
		}
	}
}