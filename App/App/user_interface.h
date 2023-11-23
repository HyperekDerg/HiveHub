#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Database/database_controller.h"
#include "Methods/add_person.h"
#include "Methods/edit_tool.h"

using namespace std;

class UserInterface {
public:
    UserInterface(const string& title, WriteDatabase& writeDatabase);
    void display() const;
    int getUserChoice() const;
    void runUserChoice() const;

private:
    string title;
    WriteDatabase& writeDatabase;
};

#endif