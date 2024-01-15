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
			system("CLS");
			userInterface.display();
			switch (int choice = userInterface.getUserChoice(); choice) {
			case 1: {
				userCreator(database);
				break;
			}
			case 2: {
				UserManagement userManagement(database);
				userManagement.runUserChoice();
				break;
			}
			case 3: {
				UserDisplay userDisplay(database);
				userDisplay.runUserChoice();
				break;
			}
			case 4:
				displayMessages("exitProgram");
				exitProgram = true;
				break;
			default:
				displayMessages("invalidChoice");
				break;
			}
		}
	}
	else {
		displayMessages("databaseError");
	}

	return 0;
}