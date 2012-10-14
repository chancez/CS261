/*
 * =====================================================================================
 *
 *       Filename:  inventory.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  06/30/2012 07:56:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>
#include "inventory.h"

using namespace std;

inventory::inventory(): MAX_WEIGHT(100), head(NULL), size(0), weight(0)
{
}

inventory::inventory(double aWeight): MAX_WEIGHT(aWeight), head(NULL), size(0), weight(0)
{
}

inventory::~inventory()
{
	node * curr = head;
	while(head)
	{
		curr = head->next;
		delete head;
		head = curr;
	}
}

bool inventory::AddItem(const item& aItem)
{
    node *prev = NULL;
    node *curr = head;

    if (!incWeight(aItem))
        return false;

    //Go through the list, finding the correct position for the item.
	while (curr!=NULL && (curr->some_item < aItem))
	{
		prev = curr;
		curr = curr->next;
	}
    //If it item exists, increment its count, and the total inventory size.
	if(curr && curr->some_item == aItem)
    {
        curr->count++;
        size++;
		return false;
    }
    //If it doesnt exist, create a new node, and copy the item to it.
	else
	{
		node * newNode = new node;
		newNode->some_item = aItem;
		newNode->next = NULL;
        newNode->count = 1;

		//link the newNode into the linked list
		newNode->next = curr;
		if(prev == NULL)
			head = newNode;
		else
			prev->next = newNode;

		size++;
		return true;
	}
}

bool inventory::RemoveItem(char *name)
{
    node *prev = NULL;
    node *curr = head;

    while (curr)
    {
        //Search until you find the correct item,
        if(strcmp(curr->some_item.getName(), name) == 0)
        {
            //if we have 1 or more items, decrement the weight, item count, and
            //total inventory size.
            if (curr->count >= 1){
                weight-= curr->some_item.getWeight();
                curr->count--;
                size--;
            }

            //If after decreasing the count, it becomes 0, then delete the node
            //from the inventory.
            if (curr->count == 0)
            {
                if(!prev)
                    head = curr->next;
                else
                    prev->next = curr->next;

                delete curr;
            }

            cout << "You dropped a " << name << "." << endl;

            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    //The item wasn't found.
    cout << "You don't have a " << name << " in your inventory." << endl;
    return false;
}

//Adds the weight of aItem to the inventory's total weight
//Returns whether or not it succeeded.
bool inventory::incWeight(const item& aItem)
{
    //If the new items weight added to the inventory total weight exceeds the
    //MAX_WEIGHT value, return a failure.
    double item_weight = aItem.getWeight();
    if((item_weight + weight) > MAX_WEIGHT)
    {
        cout << "You're not strong enough to pick up the " << aItem << " with everything else you're carrying." << endl;
        return false;
    }
    else
    {
        cout << "You picked up a " << aItem << "." << endl;
        weight+=item_weight;
        return true;
    }

}

int inventory::GetCount() const
{
    return size;
}

double inventory::GetWeight() const
{
    return weight;
}

void inventory::PrintInventory() const
{
    node *curr = head;

    int total_count = GetCount();
    double total_weight = GetWeight();

    cout << "\nCurrent inventory:" << endl;

    if (!total_count)
    {
        cout << "\t(no items)" << endl << endl;
    }
    else
    {
        while (curr != NULL)
        {
            cout << "\t[" << curr->count << "] " << curr->some_item << endl;
            curr = curr->next;
        }
        cout << "Total items: "  << total_count << endl;
        cout << "Total weight: "  << total_weight << endl << endl;
    }
}



