#ifndef EDIT_TOOL_H
#define EDIT_TOOL_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../Database/database_controller.h"
#include "Edits_Methods/remove_person.h"

using namespace std;

class EditTool
{
public:
	EditTool(WriteDatabase& writeDatabase);
	void menu() const;
	int getUserChoice() const;
	void runUserChoice() const;
private:
	WriteDatabase& writeDatabase;
};

#endif
