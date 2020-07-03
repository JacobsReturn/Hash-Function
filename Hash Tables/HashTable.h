#pragma once

class HashTable {
    public:
        HashTable(unsigned int tableSize);
        ~HashTable();

        unsigned int Hash(std::string str);

        unsigned int RSHash(const char* str, unsigned int length);

        struct info
        {
            std::string key;
            std::string value;
        };

        int size;
        info** table = new info * [size];

        void Add(std::string input, std::string number);
        info* Find(std::string find);

        void Remove(std::string find);
}; 