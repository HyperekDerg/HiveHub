#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../../common_includes.h"

#include "../../Database/database_controller.h"
#include "../methods.h"

using namespace std;

class UserInterface {
public:
	UserInterface(const string& title, WriteDatabase& writeDatabase);
	void display() const;
	int getUserChoice() const;

private:
	string title;
	WriteDatabase& writeDatabase;
};

class UserManagement
{
public:
	UserManagement(WriteDatabase& writeDatabase);
	void menu() const;
	int getUserChoice() const;
	void runUserChoice() const;
private:
	WriteDatabase& writeDatabase;
};


class UserDisplay
{
public:
	UserDisplay(WriteDatabase& writeDatabase);
	void menu() const;
	int getUserChoice() const;
	void runUserChoice() const;
private:
	WriteDatabase& writeDatabase;
};

#endif