#ifndef LINE_PARSER_H
#define LINE_PARSER_H

#include <string>
#include <vector>

struct UserData;

class LineParser {
public:
	static bool parseLine(const std::string& line, UserData& userData);
};

#endif
