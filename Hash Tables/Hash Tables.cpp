#include <iostream>
#include "HashTable.h"
#include <string>

int main()
{
    HashTable* hashTable = new HashTable(5);

    hashTable->Add("Jacob Cooper", "0420624610");

    std::cout << "Commands:" << std::endl << "!add -- Adds a value to the table." << std::endl << "!find -- Find a value" << std::endl << "!remove -- Remove a value" << std::endl;

    while (true)
    {
        std::string input;
        std::cin >> input;

        std::cin.ignore();

        if (input == "!add")
        {
            std::cout << "Write the name to add" << std::endl;

            std::string name;
            std::string phone;
            std::getline(std::cin, name);

            std::cout << "Write the number to add" << std::endl;
            std::getline(std::cin, phone);

            hashTable->Add(name, phone);

            std::cout << "Adding: " << name << " now!" << std::endl;
        }
        else if (input == "!find")
        {
            std::cout << "Write the name to search for" << std::endl;

            std::string find;
            std::getline(std::cin, find);

            HashTable::info* found = hashTable->Find(find);
            
            if (found != nullptr)
            {
                std::cout << "Found user!" << std::endl << "Name: " << found->name << std::endl << "Phone: " << found->phone << std::endl;
            }
            else std::cout << "User was not found!" << std::endl;
        }
        else if (input == "!remove")
        {
            std::cout << "Write the name to remove (if it exists)" << std::endl;

            std::string find;
            std::getline(std::cin, find);

            HashTable::info* found = hashTable->Find(find);

            if (found != nullptr)
            {
                std::cout << "Found user! Removing now..." << std::endl;

                hashTable->Remove(find);
            }
            else std::cout << "User was not found!" << std::endl;
        }
    };
}