/*
 * =====================================================================================
 *
 *       Filename:  inventory.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/30/2012 07:41:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.h"

class inventory
{
public:
    inventory();
    inventory(double aWeight);
    ~inventory();

    bool AddItem(const item& aItem);
    bool RemoveItem(char *name);
    bool incWeight(const item& aItem);

    int GetCount() const;
    double GetWeight() const;
    void PrintInventory() const;

private:
    struct node
    {
        item some_item; //the item
        int count;  //how many of the item we have;
        node *next; //the next item on the list
    };

    node *head;             //The head of the list (the first item)
    const int MAX_WEIGHT;   //How much total weight can the inventory have.
    int size;               //How big the list is
    double weight;          //Total inventory weight
};
#endif
