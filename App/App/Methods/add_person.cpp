#include "add_person.h"

void userCreator(WriteDatabase& writeDatabase) {
    cout << endl << "Welcome to the user Creation Tool. This tool allows you to add a new person to the database." << endl;
    cout << "Please prepare data in the following format: [Email | FirstName | LastName | Address | Interests]" << endl;

    string email, firstName, lastName, address, interestInput;
    vector<string> interests;

    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter First Name: ";
    cin >> firstName;
    cout << "Enter Last Name: ";
    cin >> lastName;
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter Interests (comma-separated): ";
    cin.ignore();
    getline(cin, interestInput);

    istringstream iss(interestInput);
    string interest;
    while (getline(iss, interest, ',')) {
        interests.push_back(interest);
    }

    ReadDatabase readDatabase(writeDatabase);
    if (readDatabase.findUserByEmail(email)) {
        cout << "ERROR:. This email already exists in the database! Please provide an email that doesn't exist." << endl;
    }
    else {
        writeDatabase.addUser(email, firstName, lastName, address, interests);
        cout << "User added to the database successfully." << endl;
    }
}