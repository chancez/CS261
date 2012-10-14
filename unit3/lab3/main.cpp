#include <iostream>
#include "Player.h"
#include "HashTable.h"
#include "PlayerDB.h"
#include <stdlib.h>

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

void Test()
{
	Player* outPlayer = NULL;

	// Test 1: Make sure that an empty player database doesn't fail
	PlayerDB pdb(cout);
	pdb.PrintDiagnostics();

	// Test 2: Try to fetch a non-user
	outPlayer = pdb.FetchPlayer("sleak");
	if (outPlayer != NULL) {
		cout << "Fetched a player when we shouldn't have..." << endl;
	}

	// Test 3: Add some players, and a duplicate
	pdb.AddPlayer(Player("Brutus",MALE));
	pdb.AddPlayer(Player("Brutus",MALE));
	pdb.AddPlayer(Player("Socrates",MALE));
	pdb.AddPlayer(Player("Sappho",FEMALE));
	pdb.PrintDiagnostics();

	// Test 4: Removing players
	pdb.RemovePlayer("Socrates");
	pdb.PrintDiagnostics();

	// Test 5: Fetch a player and make sure that it is the correct one
	outPlayer = pdb.FetchPlayer("Sappho");
	if (outPlayer != NULL) {
		outPlayer->LevelUp();
	}
	pdb.PrintDiagnostics(); // Note that the level for Sappho should be "1" now

	// Test 6: Try some degenerate cases
	pdb.AddPlayer(Player("a long player name to make sure our hash function will work with long names.",FEMALE));
	pdb.PrintDiagnostics();

	// Test 7: Add a bunch more players
	pdb.AddPlayer(Player("Hypatia",FEMALE));
	pdb.AddPlayer(Player("Corinna",FEMALE));
	pdb.AddPlayer(Player("Euripides",MALE));
	pdb.AddPlayer(Player("Sophocles",MALE));
	pdb.AddPlayer(Player("Aristophanes",MALE));
	pdb.PrintDiagnostics();

	// Test 8: Removing stuff in various positions in the linked list
	pdb.RemovePlayer("Hypatia");
	pdb.RemovePlayer("Brutus");
	pdb.PrintDiagnostics();
}

int main()
{

	Test();

	#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		cout << "Memory leaks!" << endl;
	}
	#endif

	return(0);
}
