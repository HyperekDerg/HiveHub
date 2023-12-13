#include "main.h"

int main() {
	const string configFileName = "config.ini";
	ConfigManager configManager(configFileName);

	if (!filesystem::exists(configFileName)) {
		configManager.createConfig();
	}
	else {
		configManager.readConfig();
	}

	const string databaseFileName = configManager.getValue("database_file");
	checkOrCreateDatabaseFile(databaseFileName);
	WriteDatabase database(databaseFileName);

	if (database.load()) {
		const string selectedColor = configManager.getValue("selected_colour");
		setConsoleColor(selectedColor);

		UserInterface userInterface("Main Menu", database);

		bool exitProgram = false;

		while (!exitProgram) {
			userInterface.display();
			userInterface.runUserChoice();
		}
	}
	else {
		cout << "Error: Failed to load the database. Exiting the program." << endl;
	}
	return 0;
}