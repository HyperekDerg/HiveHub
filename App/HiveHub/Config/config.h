#ifndef CONFIG_H
#define CONFIG_H

#include "../common_includes.h"

#include "console_utils.h"
#include "../Methods/methods.h"
#include "database_controller.h"

using namespace std;

class ConfigManager {
public:
	ConfigManager(const string& filename);
	bool readConfig();
	void writeConfig();
	string getValue(const string& key);
	void createConfig();
	void initConfig();

private:
	string filename_;
	map<string, string> configMap_;
};

void checkOrCreateDatabaseFile(const string& filename);
#endif