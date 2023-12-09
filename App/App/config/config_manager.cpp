#include "config.h"

ConfigManager::ConfigManager(const string& filename) : filename_(filename) {}

bool ConfigManager::readConfig() {
	ifstream configFile(filename_);

	if (!configFile.is_open()) {
		cerr << "Error opening config file. Exiting the application." << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(configFile, line)) {
		size_t delimiterPos = line.find('=');
		if (delimiterPos != string::npos) {
			string key = line.substr(0, delimiterPos);
			string value = line.substr(delimiterPos + 1);
			configMap_[key] = value;
		}
	}

	configFile.close();
	return true;
}

void ConfigManager::writeConfig() {
	ofstream configFile(filename_);

	if (!configFile.is_open()) {
		cerr << "Error creating config file. Exiting the application." << endl;
		exit(EXIT_FAILURE);
	}

	configFile << "## Welcome to HiveHub config file. You can set up here Database file name, language, console colour." << endl;
	configFile << endl;
	configFile << "## Database file name" << endl;
	configFile << "database_file=" << configMap_["database_file"] << endl;
	configFile << endl;
	configFile << "## Selected Language [EN\\PL]" << endl;
	configFile << "selected_language=" << configMap_["selected_language"] << endl;
	configFile << endl;
	configFile << "## Console Text Color [DEFAULT\\RED\\WHITE\\GREEN\\PINK\\YELLOW\\BLUE\\CYAN\\MAGENTA\\GRAY\\BRIGHT_RED\\BRIGHT_GREEN\\BRIGHT_BLUE\\BRIGHT_YELLOW]" << endl;
	configFile << "selected_colour=" << configMap_["selected_colour"] << endl;

	configFile.close();
}

string ConfigManager::getValue(const string& key) {
	if (configMap_.count(key)) {
		return configMap_[key];
	}
	return "";
}

void ConfigManager::createConfig() {
	cout << "####################" << endl;
	cout << "Creating a new configuration file." << endl;
	cout << "####################" << endl;

	cout << endl << "Enter the database file name: ";
	cin >> configMap_["database_file"];

	cout << "Select language [EN/PL]: ";
	cin >> configMap_["selected_language"];

	cout << "Select console text color [FROM BELOW]:\n";

	const string colorOptions[] = { "DEFAULT", "RED", "WHITE", "GREEN", "PINK", "YELLOW", "BLUE", "CYAN", "MAGENTA", "GRAY", "BRIGHT_RED", "BRIGHT_GREEN", "BRIGHT_BLUE", "BRIGHT_YELLOW" };
	const int tableColumns = 4;
	cout << endl << "####################" << endl;
	for (int i = 0; i < sizeof(colorOptions) / sizeof(colorOptions[0]); ++i) {
		setConsoleColor(colorOptions[i]);
		cout << " " << colorOptions[i] << " ";

		if ((i + 1) % tableColumns == 0) {
			cout << "\n";
		}
	}
	setConsoleColor("DEFAULT");
	cout << endl << "####################" << endl;

	cout << "\nYour choice: ";
	cin >> configMap_["selected_colour"];

	writeConfig();

	cout << endl << "####################" << endl;
	cout << "Configuration file created successfully." << endl;
	cout << endl << "####################" << endl;
}