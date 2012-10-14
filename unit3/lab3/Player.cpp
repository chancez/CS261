/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#include "Player.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

Player::Player(): playerName(NULL), playerLevel(0), playerGender(UNKNOWN)
{
}

Player::Player(char* aName, gender aGender): playerName(NULL), playerLevel(0), playerGender(UNKNOWN)
{
    setName(aName);
    setGender(aGender);
}

Player::Player(const Player& aPlayer): playerName(NULL), playerLevel(0), playerGender(UNKNOWN)
{
    setName(aPlayer.playerName);
    setGender(aPlayer.playerGender);
    setLevel(aPlayer.playerLevel);
}

const Player& Player::operator=(const Player& aPlayer)
{
    setName(aPlayer.playerName);
    setGender(aPlayer.playerGender);
    setLevel(aPlayer.playerLevel);
}

Player::~Player()
{
    if (playerName)
        delete [] playerName;
}

void Player::LevelUp()
{
    this->playerLevel++;
}

void Player::setName(char* aName)
{
    if (this->playerName)
        delete [] this->playerName;

    this->playerName = new char[strlen(aName)+1];
    strcpy(this->playerName, aName);
}

void Player::setGender(gender aGender)
{
    this->playerGender = aGender;
}

void Player::setLevel(int level)
{
    this->playerLevel = level;
}

gender Player::getGender() const
{
    return playerGender;
}

int Player::getLevel() const
{
    return playerLevel;
}

char *Player::getName() const
{
    return playerName;
}

ostream& operator<<(ostream& out, const Player& aPlayer)
{
    out << aPlayer.getName() << " [" << aPlayer.getLevel() << "]";

    return out;
}
