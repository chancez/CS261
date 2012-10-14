/*
 * =====================================================================================
 *
 *       Filename:  HashTable.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */
#include "HashTable.h"
#include <stdlib.h>
#include <string.h>

HashTable::HashTable():
    size(0),
    capacity(DEFAULT_CAPACITY),
    table(new node*[DEFAULT_CAPACITY])
{
    for (int i=0; i < capacity; i++)
        table[i] = NULL;
}

void HashTable::destroyTable()
{
    // Delete each item one by one.
    for(int i=0; i < capacity; i++)
    {
        node *head = table[i];
        node *curr;

        while(head)
        {
            curr = head->next;
            head->next = NULL;
            delete head;
            head = curr;
        }
    }
    // Delete the array
    delete [] table;
}

HashTable::~HashTable()
{
    destroyTable();
}

HashTable::HashTable(const HashTable& aTable):
    capacity(aTable.capacity),
    size(aTable.size)
{
    table = new node*[capacity];

    for(int i=0; i < capacity; i++)
    {
        if (aTable.table[i] == NULL)
            table[i] = NULL;
        else
        {
            //copy the first node in current chain
            table[i] = new node(aTable.table[i]->item);

            //copy the rest of the chain
            node * srcNode = aTable.table[i]->next;
            node * destNode = table[i];
            while(srcNode)
            {
                destNode->next = new node(srcNode->item);
                destNode = destNode->next;
                srcNode = srcNode->next;
            }
            destNode->next = NULL;
        }
    }
}

const HashTable& HashTable::operator=(const HashTable& aTable)
{
    if (this == &aTable)
        return *this;

    else
    {
        // Delete and reallocate the new space.
        destroyTable();

        table = new node*[capacity];
        size = aTable.size;
        capacity = aTable.capacity;

        int i;
        for (i = 0; i < capacity; i++)
        {
            if (aTable.table[i] == NULL)
                table[i] = NULL;
            else
            {
                table[i] = new node(aTable.table[i]->item);

                node *source = aTable.table[i]->next;
                node *destination = table[i];

                while (source)
                {
                    destination->next = new node(source->item);
                    destination = destination->next;
                    source = source->next;
                }
                destination->next = NULL;
            }
        }
        return *this;
    }
}

void HashTable::insert (char const * const name, const Player& aPlayer)
{
    //calculate the insertion position (the index of the array)
    int index = calculateIndex(name);

    //create a new node to hold Player
    node *newNode = new node(aPlayer);

    //insert the new node at the beginning of the linked list
    newNode->next = table[index];
    table[index] = newNode;
    size++;
}

bool HashTable::remove (char const * const name)
{
    //calculate the removal position (the index of the array)
    int index = calculateIndex(name);

    //search for the Player to be removed in the chain (linked list)
    node *curr = table[index];
    node *prev = NULL;
    char *playerName;

    while (curr)
    {
        playerName = curr->item.getName();

        if(strcmp(name, playerName) == 0)
        {
            //find match and remove the node
            if(!prev)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            curr->next = NULL;
            delete curr;
            size--;
            return true;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

bool HashTable::retrieve (char const * const name, Player** aPlayer) const
{
    //calculate the retrieval position (the index of the array)
    int index = calculateIndex(name);

    //search for the Player in the chain (linked list)
    node *curr = table[index];
    char *playerName;

    while (curr)
    {
        playerName = curr->item.getName();

        if(strcmp(name, playerName) == 0)
        {
            //find match and return the Player
            *aPlayer = &curr->item;
            return true;
        }
        else
            curr = curr->next;
    }

    //Player is not in the table
    return false;
}

int HashTable::getSize(void) const
{
    return size;
}

int HashTable::getCapacity(void) const
{
    return capacity;
}

int HashTable::calculateIndex(char const * const name) const
{
    int length = strlen(name);
    int i;
    unsigned int sum = int(name[0]);

    // Start at 1 because the value for the first character was done above.
    for (i = 1; i < length; i++)
    {
        sum = (sum * 32 + int(name[i]));
    }

    return sum % DEFAULT_CAPACITY;
}

ostream& operator<<(ostream& out, HashTable& aTable)
{
    int i;
    HashTable::node * curr;

    for(i=0; i < aTable.capacity; i++)
    {
        out << "Slot[" << i << "]:" << endl;
        if (aTable.table[i] == NULL)
            out << "  EMPTY" << endl;

        for(curr = aTable.table[i]; curr; curr = curr->next)
            out << "  " << curr->item << endl;

    }

    return out;
}

