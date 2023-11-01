#include "user_interface.h"

using namespace std; // Allows using the std namespace without the "std::" prefix

UserInterface::UserInterface(const string& title) : title(title) {
    // Constructor initializes the menu object with the given title
}

void UserInterface::display() const {
    cout << "=== " << title << " ===" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "4. Option 4" << endl;
    cout << "5. Option 5" << endl;
    cout << "6. Exit" << endl;
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
        // Call the subroutine for Option 1
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
