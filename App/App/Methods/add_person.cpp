#include "add_person.h"

void userCreator(WriteDatabase& writeDatabase) {
    cout << "[MAIN|CREATION]" << endl << endl;
    cout << "Welcome to the user Creation Tool. This tool allows you to add a new person to the database." << endl;
    cout << "Please prepare data in the following format: [Email | FirstName | LastName | Address | Interests]" << endl;

    string email, firstName, lastName, address, interestInput;
    vector<string> interests;

    cout << "Enter Email: ";
    cin >> email;
    cin.ignore();
    cout << "Enter First Name: ";
    cin >> firstName;
    cin.ignore();
    cout << "Enter Last Name: ";
    cin >> lastName;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Interests (comma-separated): ";
    getline(cin, interestInput);

    istringstream iss(interestInput);
    string interest;
    while (getline(iss, interest, ',')) {
        interests.push_back(interest);
    }


    ReadDatabase readDatabase(writeDatabase);
    if (readDatabase.findUserByEmail(email)) {
        cout << "ERROR:. This email already exists in the database! Please provide an email that doesn't exist." << endl;
        _sleep(2500);
    }
    else {
        writeDatabase.addUser(email, firstName, lastName, address, interests);
        cout << "User added to the database successfully." << endl;
        _sleep(2500);
    }
}