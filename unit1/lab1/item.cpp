/*
 * =====================================================================================
 *
 *       Filename:  item.cpp
 *
 *        Version:  1.0
 *        Created:  06/30/2012 07:19:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */
#include "item.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#pragma warning(disable:4996)		// allow call to strcpy

using namespace std;

item::item(): name(NULL), weight(0)
{
}

item::item(char* name, double weight): name(NULL), weight(weight)
{
    item::setName(name);
}

item::~item()
{
    if (name)
        delete [] name;
}

//Used when going to store the name
void item::getName(char* name) const
{
	strcpy(name, this->name);
}

//Easier way to access the name without declaring any variables.
char *item::getName() const
{
    return this->name;
}

double item::getWeight() const
{
    return this->weight;
}

void item::setName(char* name)
{
    //If it has a name already, delete it
	if(this->name)
		delete [] this->name;

    //Allocate enough space for the new name, and assign it
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void item::setWeight(double weight)
{
    this->weight = weight;
}

ostream& operator<<(ostream& out, const item& aItem)
{
	out << aItem.name;
		return out;
}

const item& item::operator=(const item& aItem)
{
    if(this == &aItem)
        return *this;

    else
    {
        setName(aItem.name);
        setWeight(aItem.weight);
    }
}

bool operator<(const item& item_1, const item& item_2)
{
	//char name_1[100];
	//char name_2[100];

	//item_1.getName(name_1);
	//item_2.getName(name_2);

	//if(strcmp(name_1, name_2) < 0)
    if(strcmp(item_1.getName(), item_2.getName()) < 0)
		return true;
	else
		return false;
}

bool operator==(const item& item_1, const item& item_2)
{
	//char name_1[100];
	//char name_2[100];

	//item_1.getName(name_1);
	//item_2.getName(name_2);

	//if(strcmp(name_1, name_2) == 0)
    if(strcmp(item_1.getName(), item_2.getName()) == 0)
		return true;
	else
		return false;
}

