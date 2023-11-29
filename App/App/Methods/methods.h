#ifndef METHODS_H
#define METHODS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "Edits_Methods/edit_methods.h"
#include "../Database/database_controller.h"

using namespace std;

void userCreator(WriteDatabase& writeDatabase);

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
