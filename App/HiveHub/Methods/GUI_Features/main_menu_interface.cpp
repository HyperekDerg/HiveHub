#include "user_interface.h"

UserInterface::UserInterface(const string& title, WriteDatabase& writeDatabase)
    : title(title), writeDatabase(writeDatabase) {}

void UserInterface::display() const {
    cout << "[MAIN MENU]" << endl << endl;
    cout << "=== " << title << " ===" << endl;
    cout << "1. Add New Person" << endl;
    cout << "2. Edit Data" << endl;
    cout << "3. Display People" << endl;
    cout << "4. Exit" << endl << endl;
}

int UserInterface::getUserChoice() const {
    int choice;
    cout << "Enter your choice (1-4): ";
    cin >> choice;
    return choice;
}

void UserInterface::runUserChoice() const {
    switch (int choice = getUserChoice(); choice) {
    case 1: {
        system("CLS");
        userCreator(writeDatabase);
        system("CLS");
        break;
    }
    case 2: {
        system("CLS");
        UserManagement userManagement(writeDatabase);
        userManagement.runUserChoice();
        system("CLS");
        break;
    }
    case 3: {
        system("CLS");
        UserDisplay userDisplay(writeDatabase);
        userDisplay.runUserChoice();
        system("CLS");
        break;
    }
    case 4:
        cout << endl << "####################" << endl;
        cout << "Exiting the program. Goodbye!" << endl;
        cout << "####################" << endl << endl;
        exit(0);
    default:
        system("CLS");
        cout << "Error: Invalid choice." << endl;
        system("PAUSE");
        system("CLS");
    }
}