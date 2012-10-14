/*
 * =====================================================================================
 *
 *       Filename:  Queue.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "Potion.h"

class Queue
{
public:
    Queue(int a_size);
    Queue(const Queue& aQueue);

    ~Queue();

    const Queue& operator= (const Queue& aQueue);

	bool enqueue(const Potion& aPotion);
	bool dequeue(Potion& aPotion);

	bool peek(Potion& aPotion)const;
	bool isEmpty(void)const;

    int qSize() const;
    int qCapacity() const;

	friend ostream& operator<<(ostream& out, Queue& aQueue);

private:
    //Since we don't know the number of items at runtime, a pointer is used
    //because an array will be allocated for it;
	Potion	*items;
    int MAX_CAPACITY;
	int		front;
	int		rear;
	int		size;
};

#endif
