#ifndef EDIT_TOOL_H
#define EDIT_TOOL_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../Database/database_controller.h"

using namespace std;

class EditTool
{
public:
	void menu() const;
	int getUserChoice() const;
	void runUserChoice() const;
};
#endif