#ifndef LINE_PARSER_H
#define LINE_PARSER_H

#include <string>
#include <vector>
#include "database_controller.h"
#include <sstream>

using namespace std;

struct UserData;

class LineParser {
public:
	static bool parseLine(const string& line, UserData& userData);
};

#endif