#include "user_interface.h"

UserInterface::UserInterface(const string& title, WriteDatabase& writeDatabase)
    : title(title), writeDatabase(writeDatabase) {}

void UserInterface::display() const {
    cout << "=== " << title << " ===" << endl;
    cout << "1. Add New Person" << endl;
    cout << "2. Edit Data" << endl;
    cout << "3. Manage Interests" << endl;
    cout << "4. Group People" << endl;
    cout << "5. Import/Export Data" << endl;
    cout << "6. End Task [EXIT]" << endl;
}

int UserInterface::getUserChoice() const {
    int choice;
    cout << "Choose an option (1-6): ";
    cin >> choice;
    return choice;
}

void UserInterface::runUserChoice() const {
    int choice = getUserChoice();
    switch (choice) {
    case 1:
        userCreator(writeDatabase);
        break;
    case 2:
        // Call the subroutine for Option 2
        break;
    case 3:
        // Call the subroutine for Option 3
        break;
    case 4:
        // Call the subroutine for Option 4
        break;
    case 5:
        // Call the subroutine for Option 5
        break;
    case 6:
        cout << "Exiting the program." << endl;
        exit(0); // Exit the program
    default:
        cout << "Invalid choice." << endl;
    }
}