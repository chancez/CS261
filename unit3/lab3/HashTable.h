/*
 * =====================================================================================
 *
 *       Filename:  HashTable.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Player.h"
#include <iostream>

using namespace std;

class HashTable
{
public:
    HashTable();
    HashTable(const HashTable& aTable);
    ~HashTable();

    const HashTable& operator=(const HashTable& aTable);

    void insert(char const * const name, const Player& aPlayer);
    bool remove(char const * const name);
    bool retrieve(char const * const name, Player** aPlayer) const;
    int getSize(void) const;
    int getCapacity(void) const;

    friend ostream& operator<<(ostream& out, HashTable& aTable);

private:

    struct node
    {
        Player item;
        node * next;
        node(const Player& aPlayer) : item(aPlayer), next(NULL) {}
    };

    node **table;
    int capacity;
    int size;
    const static int DEFAULT_CAPACITY = 3;

    void destroyTable();
    int calculateIndex(char const * const name) const;

};
#endif
