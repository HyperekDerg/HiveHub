#ifndef DISPLAY_METHODS_H
#define DISPLAY_METHODS_H

#include "../../common_includes.h"

#include "../../Database/database_controller.h"
#include "../methods.h"

using namespace std;

void displayByEmail(WriteDatabase& writeDatabase);
void displayByInterests(WriteDatabase& writeDatabase);
void displayEveryone(WriteDatabase& writeDatabase);
#endif