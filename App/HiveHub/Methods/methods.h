#ifndef METHODS_H
#define METHODS_H

#include "../common_includes.h"

#include "Edits_Methods/edit_methods.h"
#include "Display_Methods/display_methods.h"
#include "../Database/database_controller.h"

using namespace std;

void userCreator(WriteDatabase& writeDatabase);
void toUpperCase(string& str);
void toLowerCase(string& str);



#endif
