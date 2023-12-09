#ifndef DISPLAY_METHODS_H
#define DISPLAY_METHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "../../Database/database_controller.h"

using namespace std;

void displayByEmail(WriteDatabase& writeDatabase);
void displayByInterests(WriteDatabase& writeDatabase);
#endif