#ifndef METHODS_H
#define METHODS_H

#include "../common_includes.h"

#include "Edits_Features/edit_methods.h"
#include "User_Display_Features/display_features.h"
#include "../Database/database_controller.h"
#include "../Config/console_utils.h"

using namespace std;

void userCreator(WriteDatabase& writeDatabase);
void toUpperCase(string& str);
void toLowerCase(string& str);
string getUserEmailForEdit();
void displayMessages(const string& str);
void setParams(const string& selectedColor, bool& exitProgram);



#endif