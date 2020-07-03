#include <iostream>
#include "HashTable.h"
#include <string>

int main()
{
    HashTable testTable(100);
    testTable.Add("Aaron", "12345");
    testTable.Add("Bob", "12345");
    testTable.Add("Sam", "12345");
    testTable.Add("Fred", "12345");
    testTable.Add("Alex", "12345");
    testTable.Add("Aaron", "98765"); // what happens if we try to insert a duplicate?

    std::cout << testTable.Find("Aaron") << std::endl; // what is printed for a known key
    std::cout << testTable.Find("9999999") << std::endl; // what is printed for a key that doesnt exist?

    testTable.Remove("Aaron");
    std::cout << testTable.Find("Aaron") << std::endl; // what is printed for a removed value;

    system("pause");
}