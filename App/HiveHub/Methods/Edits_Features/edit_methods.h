#ifndef EDIT_METHODS_H
#define EDIT_METHODS_H

#include "../../common_includes.h"

#include "../../Database/database_controller.h"
#include "../methods.h"

using namespace std;

void userRemove(WriteDatabase& writeDatabase);
void editFirstName(WriteDatabase& writeDatabase);
void editLastName(WriteDatabase& writeDatabase);
void editInterests(WriteDatabase& writeDatabase);

#endif