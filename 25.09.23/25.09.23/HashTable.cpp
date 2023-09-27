#include "HashTable.h"

HashTable::HashTable(int tableSize)
{
    this->tableSize = tableSize;
    table.resize(tableSize);

    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}

int HashTable::HashFunct(const string& key)
{
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 31 + static_cast<int>(c)) % tableSize;
    }
    return abs(hash);
}

void HashTable::add(const string& key, const string& value)
{
    int index = HashFunct(key);
    KeyValuePair* newNode = new KeyValuePair(key, value);

    if (table[index] == nullptr)
    {
        table[index] = newNode;
    }
    else
    {
        KeyValuePair* current = table[index];
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        KeyValuePair* current = table[i];
        while (current != nullptr) {
            cout << "Key: " << current->key << ", Value: " << current->value << endl;
            current = current->next;
        }
    }
}

string HashTable::search(string searchInd)
{
    int index = HashFunct(searchInd);

    KeyValuePair* current = table[index];
    while (current != nullptr)
    {
        if (current->key == searchInd)
        {
            return current->value;
        }
        current = current->next;
    }

    return "";
}
void HashTable::remove(const string& key)
{
    int index = HashFunct(key);
    KeyValuePair* current = table[index];
    KeyValuePair* prev = nullptr;

    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (prev == nullptr)
            {
                table[index] = current->next;
                delete current;
            }
            else
            {
                prev->next = current->next;
                delete current;
            }
            return; 
        }
        prev = current;
        current = current->next;
    }
}
