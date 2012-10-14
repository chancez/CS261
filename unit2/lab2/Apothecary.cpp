/*
 * =====================================================================================
 *
 *       Filename:  Apothecary.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */

#include "Apothecary.h"
#include "main.h"
#include <assert.h>

Apothecary::Apothecary(int order_size, int shelf_size)
{
    //Create a queue and stack object during runtime.
    order = new Queue(order_size);
    shelf = new Stack(shelf_size);
}

Apothecary::~Apothecary()
{
    delete order;
    delete shelf;
}

const Apothecary& Apothecary::operator= (const Apothecary& anApothecary)
{
    if (this == & anApothecary)
        return *this;

    else
    {
        //Each ADT here has the = operator overloaded,
        //Use it to copy the value from the other apothecarys data.
        order = anApothecary.order;
        shelf = anApothecary.shelf;
        return *this;
    }
}

Apothecary::Apothecary(const Apothecary& anApothecary)
{
    //The = operator is overloaded for both stack and queue objects
    order = anApothecary.order;
    shelf = anApothecary.shelf;
}


bool Apothecary::OrderPotion(PotionType type)
{
    Potion aPotion(type);

    //Attempt to create potion, returns true if added, false if not
    return order->enqueue(aPotion);
}

int Apothecary::MakePotions()
{
    int i;
    Potion aPotion;
    //Begin by checking if the order queue is empty
    for (i = 0; !order->isEmpty() ; i++)
    {
        //If the queue is empty, but the shelf is full,
        //than print that its full.
        if(shelf->isFull() == true)
        {
            cout << "The shelf of potions is full.  You can't make any more until somebody buys some." << endl;
            break;
        }
        //Otherwise, take it off the order, put it onto the shelf.
        else
        {
            order->dequeue(aPotion);
            shelf->push(aPotion);
            cout << "Made a " << PotionTypeString(aPotion.GetType()) << " potion." << endl;
        }
    }

    return i; //Return the number of potions made;
}

bool Apothecary::BuyPotion(Potion& aPotion)
{
    return shelf->pop(aPotion);
}

