#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

const int TABLE_SIZE = 1000;

template <class T>
class hasher
{
public:
    hasher *next;
    T value;
    int key;
    hasher(int key, T value)
    {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }
};

template <class T>
class hashMap {
    hasher<T> **htable;

public:
    hashMap();
    ~hashMap();
    int hashFunc(int key);
    void insert(int key, T value);
    void remove(int key);
    int search(int key);
};

void zadanie2();

template <class T> hashMap<T>::hashMap()
{
    htable = new hasher<T>*[TABLE_SIZE];
    for (int i=0; i<TABLE_SIZE; i++)
        htable[i] = nullptr;
}

template <class T> hashMap<T>::~hashMap()
{
    for (int i=0; i<TABLE_SIZE; ++i)
    {
        hasher<T> *entry = htable[i];
        while (entry)
        {
            hasher<T> *prev = entry;
            entry = entry->next;
            delete &prev;
        }
    }
    delete[] htable;
}

template <class T> int hashMap<T>::hashFunc(int key)
{
    return key % TABLE_SIZE;
}

template <class T> void hashMap<T>::insert(int key, T value)
{
    int hash_value = hashFunc(key);
    hasher<T> *prev = nullptr;
    hasher<T> *entry = htable[hash_value];
    while (entry)
    {
        prev = entry;
        entry = entry->next;
    }
    if (!entry)
    {
        entry = new hasher<T>(key, value);
        if (!prev)
            htable[hash_value] = entry;
        else
            entry->value = value;
    }
}

template <class T> void hashMap<T>::remove(int key)
{
    int hash_value = hashFunc(key);
    hasher<T> *entry = htable[hash_value];
    hasher<T> *prev = nullptr;
    if (!entry || entry->key != key)
    {
        std::cout << "Nie ma elementu o takim kluczu:" << key << std::endl;
        return;
    }
    while (entry->next)
    {
        prev = entry;
        entry = entry->next;
    }
    if (prev)
        prev->next = entry->next;
    delete entry;
    std::cout << "Element usuniety" << std::endl;
}

template <class T> int hashMap<T>::search(int key)
{
    
    int hash_value = hashFunc(key);
    hasher<T> *entry = htable[hash_value];
    
    while (entry)
    {
        if(entry->key == key)
        {
            std::cout << entry->value << std::endl;
            
            return 1;
        }
        if(entry->next)
            entry = entry->next;
        else 
        {
            std::cout << "Nie ma elementu o takim kluczu:" << key << std::endl;
            return 0;
        }
    }
    
        
}

int main()
{
    hashMap<std::string> hash;
    //dodawanie
    for (auto i=0; i<1000; i++)
    {
        std::string value = std::to_string(i);
        hash.insert(i, value);
    }
    //usuwanie
    for (auto i=0; i<1000; i+=5)
    {
        hash.remove(i);
    }
    
    //szukanie istniej�cych
    hash.search(11);
    hash.search(203);
    hash.search(999);
    //szukanie nieistniej�cych
    hash.search(50);
    hash.search(100);
    hash.search(1555);
    return 0;
}
