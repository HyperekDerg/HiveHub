#include "add_person.h"

void userCreator(WriteDatabase& writeDatabase) {
    cout << "[MAIN|CREATION]" << endl << endl;
    cout << "Welcome to the user Creation Tool. This tool allows you to add a new person to the database." << endl;
    cout << "Please prepare data in the following format: [Email | FirstName | LastName | Address | Interests]" << endl << endl;

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
        cout << endl << "####################" << endl;
        cout << "ERROR:. This email already exists in the database! Please provide an email that doesn't exist." << endl;
        cout << "####################" << endl;
        system ("PAUSE");
    }
    else {
        writeDatabase.addUser(email, firstName, lastName, address, interests);
        cout << endl << "####################" << endl;
        cout << "SUCCESS:. User added to the database successfully." << endl;
        cout << "####################" << endl;
        system ("PAUSE");
    }
}