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

unsigned int HashTable::Hash(std::string str)
{
    unsigned int hashedKey = RSHash(str.c_str(), 10);
    hashedKey = hashedKey % size;

    return hashedKey;
}

void HashTable::Add(std::string key, std::string number)
{
    unsigned int hashedKey = Hash(key);

    info* input = new info();
    input->key = key;
    input->value = number;

    table[hashedKey] = input;

    std::cout << input->key << " " << input->value << " " << table[hashedKey]->key << " " << hashedKey << std::endl;
}

HashTable::info* HashTable::Find(std::string find)
{
    unsigned int hashedKey = Hash(find);

    std::cout << find << " " << hashedKey << std::endl;

    //if (size >= hashedKey) return nullptr;

    if (table[hashedKey] != nullptr && table[hashedKey]->key == find)
    {
        return table[hashedKey];
    }

    return nullptr;
}

void HashTable::Remove(std::string find)
{
    unsigned int hashedKey = Hash(find);

    if (table[hashedKey] == nullptr) return;

    if (table[hashedKey] != nullptr && table[hashedKey]->key == find)
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