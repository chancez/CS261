/*
 * =====================================================================================
 *
 *       Filename:  item.h
 *
 *    Description:  This file contains the item class which holds all the
 *    attributes of items a player may hold.
 *
 *        Version:  1.0
 *        Created:  06/30/2012 07:13:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef ITEM_H
#define ITEM_H
#include <iostream>
using namespace std;

class item
{
public:
    //Constructors, copier, and destructor
    item();
    item(char* name, double weight);
    item(const item& AItem);
    ~item();

    //Getters
    void getName(char *name) const;
    char *getName() const;
    double getWeight() const;

    //Setters
    void setName(char* name);
    void setWeight(double weight);

	friend ostream& operator<<(ostream& out, const item& aItem);
	const item& operator=(const item& aItem);

private:
    char* name;
    double weight;
};

//Operators
bool operator< (const item& item_1, const item& item_2);
bool operator== (const item& item_1, const item& item_2);

#endif
