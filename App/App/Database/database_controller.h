#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <string>
#include <vector>
#include <map>

struct UserData
{
	std::string email;
	std::string firstName;
	std::string lastName;
	std::string address;
	std::vector<std::string> interests;
};

class WriteDatabase {
public:
	WriteDatabase(const std::string& filename);
	~WriteDatabase();

	void addUser(const std::string& email, const std::string& firstName, const std::string& lastName, const std::string& address, const std::vector<std::string>& interests);
	bool removeUser(const std::string& email);

	bool load();
	bool save();
	const std::map<std::string, UserData>& getUserMap() const {
		return userMap;
	}

private:
	std::string filename_;
	std::map<std::string, UserData> userMap;
};

class ReadDatabase {
public:
	ReadDatabase(const WriteDatabase& writeDatabase);
	void displayUser(const UserData& userData);
	bool findUserByEmail(const std::string& email);
	bool findUsersByInterests(const std::vector<std::string>& interests);
private:
	const WriteDatabase& writeDatabase_;
};

#endif