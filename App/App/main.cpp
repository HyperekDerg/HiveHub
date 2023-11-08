// main.cpp: Defines the entry point for the application.

#include "main.h"

int main() {
    cout << "Hello HiveHub" << endl;

    WriteDatabase database("database.txt");

    if (database.load()) {
        UserInterface userInterface("Main Menu", database);

        bool exitProgram = false;

        while (!exitProgram) {
            userInterface.display();
            userInterface.runUserChoice();
        }
    }
    else {
        cout << "Failed to load the database." << endl;
    }

    return 0;
}