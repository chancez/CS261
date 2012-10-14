/*
 * =====================================================================================
 *
 *       Filename:  Potion.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "main.h"
#include "Potion.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

Potion::Potion(): type(UNKNOWN)
{
}

Potion::Potion(PotionType type)
{
    SetType(type);
}

const Potion& Potion::operator=(const Potion& aPotion)
{
    if (this == &aPotion)
        return *this;

    else
    {
        type = aPotion.type;
        return *this;
    }
}

Potion::Potion(const Potion& aPotion)
{
    type = aPotion.type;
}

PotionType Potion::GetType() const
{
    return type;
}

void Potion::SetType(PotionType type)
{
    this->type = type;
}

ostream& operator<<(ostream& out, const Potion& aPotion)
{
    out << "Potion of " << PotionTypeString(aPotion.type) << endl;
    return out;
}

