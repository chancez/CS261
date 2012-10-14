/*
 * =====================================================================================
 *
 *       Filename:  Apothecary.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef APOTHECARY_H
#define APOTHECARY_H
#include <iostream>
#include <stdlib.h>
#include "main.h"
#include "Queue.h"
#include "Stack.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

class Apothecary
{
public:
    Apothecary(int order_size, int shelf_size);
    ~Apothecary();

    Apothecary(const Apothecary& anApothecary);
    const Apothecary& operator= (const Apothecary& anApothecary);

    bool OrderPotion(PotionType type);
    int MakePotions();
    bool BuyPotion(Potion& aPotion);

private:
    //Using pointers because we dont know how big the queue and stack will be
    //until the Apothecary object is created.
    Queue *order;
    Stack *shelf;

};

#endif
