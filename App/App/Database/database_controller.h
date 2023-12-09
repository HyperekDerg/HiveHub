#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

struct UserData
{
	string email;
	string firstName;
	string lastName;
	string address;
	vector<string> interests;
};

class WriteDatabase {
public:
	WriteDatabase(const string& filename);
	~WriteDatabase();

	void addUser(const string& email, const string& firstName, const string& lastName, const string& address, const vector<string>& interests);
	bool removeUser(const string& email);
	bool updateUser(const string& email, const UserData& updatedUserData);

	bool load();
	bool save();
	const map<string, UserData>& getUserMap() const {
		return userMap;
	}

private:
	string filename_;
	map<string, UserData> userMap;
};

class ReadDatabase {
public:
	ReadDatabase(const WriteDatabase& writeDatabase);

	UserData getUser(const string& email) const;
	void displayUser(const UserData& userData, ostream& output);

	bool findUserByEmail(const string& email);
	bool findUsersByInterests(const vector<string>& interests, ostream& output);
private:
	const WriteDatabase& writeDatabase_;
	map<string, UserData> userMap;
};

class LineParser {
public:
	static bool parseLine(const string& line, UserData& userData);
};
#endif