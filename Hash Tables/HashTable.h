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
            bool inUse = false;
        };

        int size = 10;
        info* table = nullptr;

        void Add(std::string input, std::string number);
        info Find(std::string find);

        void Remove(std::string find);
}; 