#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <iostream>
#include <vector>
#include <string>

class UserInterface {
public:
    UserInterface(const std::string& title);
    void display() const;
    int getUserChoice() const;
    void runUserChoice() const;

private:
    std::string title;
};

#endif // USER_INTERFACE_H
