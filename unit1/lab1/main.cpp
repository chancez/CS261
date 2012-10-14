#include <iostream>
#include "item.h"
#include "inventory.h"
#include <stdlib.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

void AddItem(inventory& inv,char* name,double weight)
{
	int len = strlen(name)+1;
	char* itemName = new char[len];
	strncpy(itemName,name,len);

	cout << "Adding " << itemName << " with a weight of " << weight << "." << endl;
	inv.AddItem(item(itemName,weight));

	delete [] itemName;
}

void RemoveItem(inventory& inv,char* name)
{
	cout << "Removing " << name << "." << endl;
	inv.RemoveItem(name);
}

void doTest()
{
	inventory inv;

	// Make sure printing an empty inventory works
	inv.PrintInventory();

	// Make sure adding the first one works
	AddItem(inv,"helmet",5);
	inv.PrintInventory();

	// Add some more items
	AddItem(inv,"braclet of power",1);
	AddItem(inv,"red potion",2);
	inv.PrintInventory();

	// Add some duplicates
	AddItem(inv,"braclet of power",1);
	inv.PrintInventory();

	// Add some heavy stuff
	AddItem(inv,"bag of gold coins",50);
	AddItem(inv,"bag of gold coins",50);


	// Now some removes
	RemoveItem(inv,"short sword");
	RemoveItem(inv,"helmet");
	RemoveItem(inv,"braclet of power");
	inv.PrintInventory();

	RemoveItem(inv,"braclet of power");
	RemoveItem(inv,"red potion");
	inv.PrintInventory();

	// Now some crazy stuff
	AddItem(inv,"the charred remains of the Staff of Law that destroyed in the battle with Elena-Raver before the fist of Collossus",1);
	AddItem(inv,"",0);
	AddItem(inv,"",0);
	AddItem(inv,"",0);
	inv.PrintInventory();



}

int main() {

	doTest();

#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		cout << "Memory leaks!" << endl;
	}
#endif

	return 0;
}
