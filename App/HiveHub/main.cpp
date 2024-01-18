#include "main.h"

int main() {
	bool exitProgram;

	ConfigManager configManager("config.ini");
	configManager.initConfig();
	WriteDatabase database(configManager.getValue("database_file"));

	if (database.load()) {
		setParams(configManager.getValue("selected_colour"), exitProgram);
		UserInterface userInterface("Main Menu", database);

		while (exitProgram == false) {
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