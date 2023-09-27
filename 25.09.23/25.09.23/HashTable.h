#pragma once
#include <vector>
#include <iostream>
using namespace std;

class HashTable
{
private:
    class KeyValuePair
    {
    public:
        string key;
        string value;
        KeyValuePair* next;

        KeyValuePair(const string& k, const string& v)
            : key(k), value(v), next(nullptr) {}
    };

    vector<KeyValuePair*> table;
    int tableSize;

public:
    HashTable(int tableSize);
    int HashFunct(const string& key);
    void add(const string& key, const string& value);
    void printTable();
    string search(string searchInd);
    void remove(const string& key);

};
