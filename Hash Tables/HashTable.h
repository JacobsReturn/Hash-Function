#pragma once

class HashTable {
    public:
        HashTable(unsigned int tableSize);
        ~HashTable();

        unsigned int RSHash(const char* str, unsigned int length);

        struct info
        {
            std::string name;
            std::string phone;
        };

        int size;
        info** table = new info * [size];

        void Add(std::string input, std::string number);
        info* Find(std::string find);

        void Remove(std::string find);
}; 