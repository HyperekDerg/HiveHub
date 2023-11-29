#include "edit_methods.h"

void editLastName(WriteDatabase& writeDatabase) {
    cout << "[MAIN|EDIT|LAST_NAME]" << endl << endl;
    cout << "To edit the last name of a user in the database, please provide the user's email" << endl << endl;

    string email;

    cout << "Enter Email: ";
    getline(cin, email);

    ReadDatabase readDatabase(writeDatabase);
    if (readDatabase.findUserByEmail(email)) {
        cout << "Enter the new Last Name: ";
        string newLastName;
        getline(cin, newLastName);

        UserData userData = writeDatabase.getUser(email);
        userData.lastName = newLastName;

        writeDatabase.updateUser(email, userData);
        cout << endl << "####################" << endl;
        cout << "Last Name updated successfully." << endl;
        cout << "####################" << endl;
        system("PAUSE");
    }
    else {
        cout << endl << "####################" << endl;
        cout << "User not found in the database. No changes made." << endl;
        cout << "####################" << endl;
        system("PAUSE");
    }
}