/*
 * =====================================================================================
 *
 *       Filename:  Potion.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef POTION_H
#define POTION_H
#include <iostream>
#include "main.h"

using namespace std;

class Potion
{
public:
    Potion();
    Potion(PotionType type);

    Potion(const Potion& aPotion);

    PotionType GetType() const;
    void SetType(PotionType type);

    const Potion& operator=(const Potion& aPotion);
    friend ostream& operator<<(ostream& out, const Potion& aPotion);

private:
    PotionType type;

};


#endif
