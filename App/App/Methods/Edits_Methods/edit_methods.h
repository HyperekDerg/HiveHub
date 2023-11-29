#ifndef EDIT_METHODS_H
#define EDIT_METHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "../../Database/database_controller.h"

using namespace std;

void userRemove(WriteDatabase& writeDatabase);
void editFirstName(WriteDatabase& writeDatabase);
void editLastName(WriteDatabase& writeDatabase);
void editInterests(WriteDatabase& writeDatabase);

#endif