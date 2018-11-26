#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <map>
#include <string>

class AddressBook
{
public:
    AddressBook();

    void insert(const std::string &name, const std::string &phoneNumber);

    void remove(const std::string &name);

    void change(const std::string &name, const std::string &phoneNumber);

    std::string find(const std::string &name);

    void clear();
private:
    std::multimap<std::string, std::string> book;
};

#endif // ADDRESSBOOK_H
