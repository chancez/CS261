#include <iostream>
#include "Apothecary.h"
#include "main.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

char* PotionTypeString(PotionType type)
{
	char* s = "";

	switch (type) {
	case SPEED:
		s =  "Speed";
		break;
	case STRENGTH:
		s =  "Strength";
		break;
	case HEALTH:
		s = "Health";
		break;
	case WISDOM:
		s = "Wisdom";
		break;
	}
	return(s);
}


void BuyPotion(Apothecary& apo)
{
	Potion potion;
	if (apo.BuyPotion(potion)) {
		cout << "Congratulations! You just bought a " << PotionTypeString(potion.GetType()) << " potion!" << endl;
		cout << potion;
	} else {
		cout << "There were no potions available." << endl;
	}
}

void OrderPotion(Apothecary& apo,PotionType type)
{
	bool ret = apo.OrderPotion(type);
	if (ret) {
		cout << "Your potion (" << PotionTypeString(type) << ") has been added to the queue!" << endl;
	} else {
		cout << "The order queue is full." << endl;
	}

}

void MakePotions(Apothecary& apo)
{
	cout << "About to try to make some potions." << endl;
	int count = apo.MakePotions();
	cout << "Made " << count << " potions." << endl;
}

void TestApothecary()
{
	Apothecary apo(5,20);  // order limit, shelf limit

	OrderPotion(apo,WISDOM);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);

	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,HEALTH);

	BuyPotion(apo);
	BuyPotion(apo);
	BuyPotion(apo);
	BuyPotion(apo);

	MakePotions(apo);

	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);
	OrderPotion(apo,STRENGTH);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,HEALTH);

	MakePotions(apo);

	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,HEALTH);
	OrderPotion(apo,WISDOM);
	OrderPotion(apo,SPEED);

	MakePotions(apo);

	BuyPotion(apo);

	MakePotions(apo);

}

int main() {

	TestApothecary();

#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		cout << "Memory leaks!" << endl;
	}
#endif

	return 0;
}
