/*
 * =====================================================================================
 *
 *       Filename:  PlayerDB.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#include "PlayerDB.h"

PlayerDB::PlayerDB(): myOut(&cout)
{
}

PlayerDB::PlayerDB(ostream& out): myOut(&out)
{
}

bool PlayerDB::AddPlayer(const Player &aPlayer)
{
    Player *temp;
    char *playerName = aPlayer.getName();

    *myOut << "Attempting to add player \"" << playerName << "\" to the database -- ";

    if (myDB.retrieve(playerName, &temp) == false)
    {
        myDB.insert(playerName, aPlayer);
        *myOut << "Success!" << endl;
        return true;
    }
    else
    {
        *myOut << "Failed." << endl;
    }

    return false;
}

bool PlayerDB::RemovePlayer(const char* const name)
{
    *myOut << "Removing player \"" << name << "\" from the database -- ";
    if (myDB.remove(name)) {
        *myOut << "Success!" << endl;
        return true;
    }

    *myOut << "Failed." << endl;
    return false;

}

Player* PlayerDB::FetchPlayer(const char* const name)
{
    Player *temp = NULL;

    *myOut << "Fetching player \"" << name << "\" -- ";

    if(myDB.retrieve(name, &temp))
        *myOut << "Success!" << endl;
    else
        *myOut << "Failed." << endl;

    return temp;
}

void PlayerDB::PrintDiagnostics()
{
    int table_size = myDB.getCapacity();
    int table_entries = myDB.getSize();

    *myOut << "====================" << endl;
    *myOut << "Hash Table Diagnostics" << endl << endl;
    *myOut << "Table Size: " << table_size << endl;
    *myOut << "Number of Entries: " << table_entries << endl;
    *myOut << myDB;
    *myOut << "====================" << endl;

}
