// main.cpp: Defines the entry point for the application.
//

#include "main.h"
#include "user_interface.h"

using namespace std;

int main()
{
    cout << "Hello HiveHub" << endl;

    UserInterface userInterface("Main Menu");  // Creates an object of the UserInterface class
    bool exitProgram = false;

    while (!exitProgram) {
        userInterface.display(); // Displays the menu
        userInterface.runUserChoice(); // Handles user's choice
    }

    return 0;
}