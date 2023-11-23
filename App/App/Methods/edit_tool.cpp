#include "edit_tool.h"


void EditTool::menu() const {
    cout << "[MAIN|EDIT]" << endl << endl;
	cout << "Welcome to Edit tool. Inside this tool you can remove user from database, change values of database records.\n";
	cout << "Before you start please select which operation do you want to do.\n";

    cout << "===  Edit Tool  ===" << endl;
    cout << "1. Remove user" << endl;
    cout << "2. Edit First Name" << endl;
    cout << "3. Edit Last Name" << endl;
    cout << "4. Edit Interests" << endl;
    cout << "5. Go back to Main Menu" << endl;
}

int EditTool::getUserChoice() const {
    int choice;
    cout << "Choose an option (1-5): ";
    cin >> choice;
    return choice;
}

void EditTool::runUserChoice() const {
    int choice = getUserChoice();
    switch (choice) {
    case 1:
        // Call the subroutine for Option 1
    case 2:
        // Call the subroutine for Option 2
    case 3:
        // Call the subroutine for Option 3
        break;
    case 4:
        // Call the subroutine for Option 4
        break;
    case 5:
        cout << "EDIT DONE" << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
    }
}