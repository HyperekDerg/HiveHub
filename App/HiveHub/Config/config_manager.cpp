#include "config.h"

ConfigManager::ConfigManager(const string& configFileName) : filename_(configFileName) {}

bool ConfigManager::readConfig() {
	ifstream configFile(filename_);

	if (!configFile.is_open()) {
		cerr << "Error opening the configuration file. Exiting the application." << endl;
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
		cerr << "Error creating the configuration file. Exiting the application." << endl;
		exit(EXIT_FAILURE);
	}

	configFile << "## Welcome to HiveHub configuration file. Set up Database file name, and console color here." << endl;
	configFile << endl;
	configFile << "## Database file name" << endl;
	configFile << "database_file=" << configMap_["database_file"] << endl;
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

	cout << endl << "Enter the database file name (press Enter for default): ";
	string tempDatabaseFile;
	getline(cin, tempDatabaseFile);
	if (tempDatabaseFile.empty()) {
		tempDatabaseFile = "DefaultDatabase";
	}
	toUpperCase(tempDatabaseFile);
	configMap_["database_file"] = tempDatabaseFile + ".txt";

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
	cin >> tempDatabaseFile;
	toUpperCase(tempDatabaseFile);

	while (find(begin(colorOptions), end(colorOptions), tempDatabaseFile) == end(colorOptions)) {
		cout << "Invalid choice. Please select a valid color option: ";
		cin >> tempDatabaseFile;
		toUpperCase(tempDatabaseFile);
	}

	configMap_["selected_colour"] = tempDatabaseFile;

	writeConfig();

	cout << endl << "####################" << endl;
	cout << "Configuration file created successfully." << endl;
	cout << "####################" << endl;
}

void ConfigManager::initConfig() {
	if (!filesystem::exists("config.ini")) {
		createConfig();
	}
	else {
		readConfig();
	}

	checkOrCreateDatabaseFile(getValue("database_file"));
}