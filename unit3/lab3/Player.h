/*
 * =====================================================================================
 *
 *       Filename:  Player.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */
#ifndef PLAYER_H
#define PLAYER_H
#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <iostream>

using namespace std;

enum gender {MALE, FEMALE, UNKNOWN};

class Player
{
public:
    Player();
    Player(char* aName, gender aGender);

    Player(const Player& aPlayer);
    const Player& operator=(const Player& aPlayer);

    ~Player();

    void LevelUp();
    void setName(char* aName);
    void setGender(gender aGender);

    char *getName() const;
    gender getGender() const;
    int getLevel() const;


    friend ostream& operator<<(ostream& out, const Player& aPlayer);

private:

    char *playerName;
    int playerLevel;
    gender playerGender;

    void setLevel(int level);
};

#endif
