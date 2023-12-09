#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include "console_utils.h"

using namespace std;

class ConfigManager {
public:
	ConfigManager(const string& filename);
	bool readConfig();
	void writeConfig();
	string getValue(const string& key);
	void createConfig();

private:
	string filename_;
	map<string, string> configMap_;
};

void checkOrCreateDatabaseFile(const string& filename);
#endif