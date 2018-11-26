#include "addressbook.h"

AddressBook::AddressBook()
{

}

void AddressBook::insert(const std::string &name, const std::string &phoneNumber)
{
    book.insert(std::make_pair(name, phoneNumber));
}

void AddressBook::remove(const std::string &name)
{
    book.erase(name);
}

void AddressBook::change(const std::string &name, const std::string &phoneNumber)
{
    try {
        auto it = book.find(name);
        auto base = it++;
        base->second = phoneNumber;

        while (it->first == name) {
            book.erase(it);
            it = base;
            it++;
        }
    } catch (...) {
        // end().second produces undefined benaviour
    }
}

std::string AddressBook::find(const std::string &name)
{
    auto value = book.find(name);
    return value != book.end() ? value->second : "";
}

void AddressBook::clear()
{
    book.clear();
}
