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
    info input;

    if (table[hashedKey].inUse)
    {
        while (!table[hashedKey].inUse)
        {
            hashedKey++;

            if (hashedKey > size)
            {
                return;
            }
        }
    }

    input.key = key;
    input.value = number;

    table[hashedKey] = input;

    std::cout << input.key << " " << input.value << " " << table[hashedKey].key << " " << hashedKey << std::endl;
}

HashTable::info HashTable::Find(std::string find)
{
    unsigned int hashedKey = Hash(find);

    std::cout << "Searching for " << find << std::endl;

    if (table[hashedKey].inUse && (table[hashedKey].key != find))
    {
        while (table[hashedKey].inUse && (table[hashedKey].key == find))
        {
            hashedKey++;

            if (hashedKey > size)
            {
                return table[0];
            }
        }
    }

    std::cout << "Found: " << find << " at index " << hashedKey << std::endl;

    //if (size >= hashedKey) return nullptr;
    
    return table[hashedKey];
}

void HashTable::Remove(std::string find)
{
    unsigned int hashedKey = Hash(find);

    if (table[hashedKey].key == find)
    {
        table[hashedKey].inUse = false;
    }
}

HashTable::HashTable(unsigned int tableSize)
{
    size = tableSize;
    table = new info[tableSize];
}

HashTable::~HashTable()
{
}