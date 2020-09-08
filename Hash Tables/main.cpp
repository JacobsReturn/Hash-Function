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

    testTable.Find("Aaron"); // what is printed for a known key
    testTable.Find("9999999"); // what is printed for a key that doesnt exist?

    testTable.Remove("Aaron");
    testTable.Find("Aaron"); // what is printed for a removed value;

    system("pause");
}