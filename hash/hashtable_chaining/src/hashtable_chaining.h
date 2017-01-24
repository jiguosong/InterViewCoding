#ifndef hashtable_chaining_H_
#define hashtable_chaining_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class LinkedHashEntry {

private:
    int key;
    int value;
    LinkedHashEntry *next;
public:
    LinkedHashEntry(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    int getKey()
    {
        return key;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    LinkedHashEntry *getNext()
    {
        return next;
    }


    void setNext(LinkedHashEntry *next)
    {
        this->next = next;
    }
};


const int TABLE_SIZE = 128;

class hashtable_chaining {
public:
    hashtable_chaining()
    {
        table = new LinkedHashEntry *[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
    }

    int get(int key)
    {
        int hash = (key % TABLE_SIZE);
        if (table[hash] == nullptr)
            return -1;
        else {
            LinkedHashEntry *entry = table[hash];
            while (entry != nullptr && entry->getKey() != key) entry = entry->getNext();
            if (entry == nullptr) return -1;
            else return entry->getValue();
        }
    }

    void put(int key, int value)
    {
        int hash = (key % TABLE_SIZE);
        if (table[hash] == nullptr)
            table[hash] = new LinkedHashEntry(key, value);
        else {
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != nullptr) entry = entry->getNext();
            if (entry->getKey() == key) entry->setValue(value);
            else entry->setNext(new LinkedHashEntry(key, value));
        }
    }

    void remove(int key)
    {
        int hash = (key % TABLE_SIZE);
        if (table[hash] != nullptr) {
            LinkedHashEntry *prevEntry = nullptr;
            LinkedHashEntry *entry = table[hash];
            while (entry->getNext() != nullptr && entry->getKey() != key) {
                prevEntry = entry;
                entry = entry->getNext();
            }
            if (entry->getKey() == key) {
                if (prevEntry == nullptr) {
                    LinkedHashEntry *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                } else {
                    LinkedHashEntry *next = entry->getNext();
                    delete entry;
                    prevEntry->setNext(next);
                }
            }
        }
    }

    ~hashtable_chaining()
    {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != nullptr) {
                LinkedHashEntry *prevEntry = nullptr;
                LinkedHashEntry *entry = table[i];
                while (entry != nullptr) {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        }

        delete[] table;
    }

private:
    LinkedHashEntry **table;
};

#endif
