#include <iostream>
#include <string>
#include "HashTable.h"

unsigned int HashTable::RSHash(const char* str, unsigned int length)
{
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;
    unsigned int i = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        hash = hash * a + (*str);
        a = a * b;
    }

    return hash;
}

void HashTable::Add(std::string name, std::string number)
{
    unsigned int hashedKey = RSHash(name.c_str(), 10);
    hashedKey = hashedKey % size;

    info* input = new info();
    input->name = name;
    input->phone = number;

    table[hashedKey] = input;
}

HashTable::info* HashTable::Find(std::string find)
{
    unsigned int hashedKey = RSHash(find.c_str(), 10);
    hashedKey = hashedKey % size;

    if (table[hashedKey] != nullptr && table[hashedKey]->name == find)
    {
        return table[hashedKey];
    }

    return nullptr;
}

void HashTable::Remove(std::string find)
{
    unsigned int hashedKey = RSHash(find.c_str(), 10);
    hashedKey = hashedKey % size;

    if (table[hashedKey] != nullptr && table[hashedKey]->name == find)
    {
        delete table[hashedKey];
    }
}

HashTable::HashTable(unsigned int tableSize)
{
    size = tableSize;
    table = new info* [tableSize];
}

HashTable::~HashTable()
{
}
