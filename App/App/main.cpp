#include "main.h"

int main() {
    const string databaseFileName = "database.txt";
    checkOrCreateDatabaseFile(databaseFileName);

    WriteDatabase database(databaseFileName);

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