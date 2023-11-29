#include "edit_methods.h"

void editFirstName(WriteDatabase& writeDatabase) {
    cout << "[MAIN|EDIT|FIRST_NAME]" << endl << endl;
    cout << "To edit the first name of a user in the database, please provide the user's email" << endl << endl;

    string email;

    cout << "Enter Email: ";
    getline(cin, email);

    ReadDatabase readDatabase(writeDatabase);
    if (readDatabase.findUserByEmail(email)) {
        cout << "Enter the new First Name: ";
        string newFirstName;
        getline(cin, newFirstName);

        UserData userData = readDatabase.getUser(email);
        userData.firstName = newFirstName;

        writeDatabase.updateUser(email, userData);
        cout << endl << "####################" << endl;
        cout << "First Name updated successfully." << endl;
        cout << "####################" << endl;
        system ("PAUSE");
    }
    else {
        cout << endl << "####################" << endl;
        cout << "User not found in the database. No changes made." << endl;
        cout << "####################" << endl;
        system("PAUSE");
    }
}