#ifndef STACK_H
#define STACK_H
#include "Potion.h"

class Stack
{
public:
	Stack(int capacity);
	~Stack();
    Stack(const Stack& aStack);

	const Stack& operator=(const Stack& aStack);

	bool push(const Potion& aPotion);
	bool pop(Potion& aPotion);

	bool peek(Potion& aPotion) const;
	bool isEmpty(void) const;
    bool isFull(void) const;

	friend ostream& operator<<(ostream& out, Stack& stk);

private:
	Potion*	items;
	int		top;

    int MAX_CAPACITY;
};

#endif
