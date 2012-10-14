#include "Stack.h"
#include <fstream>
#include <assert.h>

Stack::Stack(int capacity):MAX_CAPACITY(capacity), top(-1)
{
    //Create a new array based on the value passed to the constructor
	items = new Potion[capacity];
}

const Stack& Stack::operator=(const Stack& aStack)
{
	if(this == &aStack)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		delete [] items; //the destructor of each Potion object in the array will be invoked

		//make a *this a deep copy of "aStack"
		MAX_CAPACITY = aStack.MAX_CAPACITY;
		items = new Potion[MAX_CAPACITY];
		top = aStack.top;

		int i;
        for(i = aStack.top; i >= 0; i--)
			items[i] = aStack.items[i]; //this is a deep copy because '=' was overloaded in Potion class
		return *this;
	}
}

Stack::Stack(const Stack& aStack)
{
    top = aStack.top;
    MAX_CAPACITY = aStack.MAX_CAPACITY;

    //Create enough space for the array
    items = new Potion[MAX_CAPACITY];
    //Make sure that the space was properly allocated
    assert(items != NULL);

    //Deep copy
    int i;
    for(i=0; i<=aStack.top; i++)
        items[i] = aStack.items[i];
}

Stack::~Stack()
{
	delete [] items;
}

bool Stack::push(const Potion& aPotion)
{
	//check if there is still space in the array
	if(top+1 == MAX_CAPACITY)
	{
        //Stack is full
		return false;
	}

	//add on top
	top++;
	items[top] = aPotion;
	return true;
}

bool Stack::pop (Potion& aPotion)
{
	//empty Stack, has nothing to pop
	if(isEmpty())
		return false;
	else
	{
		aPotion = items[top];
		top--;
		return true;
	}
}

bool Stack::isEmpty () const
{
	return top<0;
}

bool Stack::isFull() const
{
    return (top+1 == MAX_CAPACITY);
}

bool Stack::peek (Potion& aPotion) const
{
	if(isEmpty())
		return false;
	else
	{
		aPotion = items[top];
		return true;
	}
}

ostream& operator<<(ostream& out, Stack& stk)
{
	int i;

	out << "Potion in the Stack: " << endl << endl;
	for(i = stk.top; i >= 0; i--)
		//we can use << on Potion object because we overload << in the Potion class
		out << '\t' << stk.items[i] << endl;

	return out;
}
