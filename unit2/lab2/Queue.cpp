/*
 * =====================================================================================
 *
 *       Filename:  Queue.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */

#include "Queue.h"
#include <assert.h>

Queue::Queue(int a_size): size(0), front(0), rear(0), MAX_CAPACITY(a_size), items(NULL)
{
    //Create an array of potions with the size passed to the constructor
    items = new Potion[a_size];
}

Queue::Queue(const Queue& aQueue)
{
    size = aQueue.size;
    front = aQueue.front;
    rear = aQueue.rear;
    MAX_CAPACITY = aQueue.MAX_CAPACITY;

    items = new Potion[MAX_CAPACITY];
    //make sure that the alloc worked before assigning the array items.
    assert(items != NULL);

    int itemsGoneThrough;
    int i;
    //Deeply copies the values.
	for (i = aQueue.front, itemsGoneThrough = 0;
			itemsGoneThrough < aQueue.size;
			i = (i + 1) % aQueue.MAX_CAPACITY, itemsGoneThrough++)
    {
        items[i] = aQueue.items[i];
    }

}

const Queue& Queue::operator= (const Queue& aQueue)
{
    if (this == &aQueue)
        return *this;

    else
    {
        //Delete array of items previously allocated.
        delete [] items;

        size = aQueue.size;
        front = aQueue.front;
        rear = aQueue.rear;
        MAX_CAPACITY = aQueue.MAX_CAPACITY;

        //Realloc space for the new array
        items = new Potion[MAX_CAPACITY];
        //Make sure that the alloc worked before assigning values
        assert(items != NULL);

        int itemsGoneThrough;
        int i;
        //Deeply copies the values into the new array
        for (i = aQueue.front, itemsGoneThrough = 0;
                itemsGoneThrough < aQueue.size;
                i = (i + 1) % aQueue.MAX_CAPACITY, itemsGoneThrough++)
        {
            //overloaded the Potions assignment operator, using it here.
            items[i] = aQueue.items[i];
        }

        return *this;
    }
}

//Needs this because the array is allocated on the heap
Queue::~Queue()
{
    delete [] items;
}

bool Queue::enqueue(const Potion& aPotion)
{
    if (size == MAX_CAPACITY)
        return false; //Returns false if the queue is full

    //Add the item to the end of the queue
    items[rear] = aPotion;
    rear = (rear + 1) % MAX_CAPACITY; //Circular, so no shifting needed.
    size++;
    return true;
}

bool Queue::dequeue(Potion& aPotion)
{
    if (isEmpty())
        return false; //If the queue is empty, returns false
    else
    {
        //Returns the first item in the queue by reference
        aPotion = items[front];
        front = (front + 1) % MAX_CAPACITY;
        size--;
        return true;
    }
}

//Returns true if empty, false if not empty
bool Queue::isEmpty() const
{
    if (size == 0)
        return true;

    return false;
}

bool Queue::peek(Potion& aPotion) const
{
    if (isEmpty())
        return false;

    else
    {
        aPotion = items[front]; //Returns the first item in the queue by reference
        return true;
    }
}

//For testing I've overloaded the << operator
ostream& operator<<(ostream& out, Queue& aQueue)
{
	int		i;
	int		nPrinted;

	out << "Data in the queue: " << endl << endl;
	for (i = aQueue.front, nPrinted = 0;
			nPrinted < aQueue.size;
			i = (i + 1) % aQueue.MAX_CAPACITY, nPrinted++)

		out << aQueue.items[i] << endl;

	return out;
}
