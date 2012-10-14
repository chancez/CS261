/*
 * =====================================================================================
 *
 *       Filename:  Skill.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#ifndef SKILL_H
#define SKILL_H

#pragma GCC diagnostic ignored "-Wwrite-strings"
#include <ostream>

using namespace std;

class Skill
{
public:
    //Constructors/Deconstructors
    Skill();
    Skill(char* name, char* description, int level);
    Skill(const Skill& aSkill);
    ~Skill();

    //Mutator methods
    void setName(char* name);
    void setDescription(char* description);
    void setLevel(int level);

    //Accessor methods
    char* getName();
    char* getDescription();
    int getLevel();

    void Display(ostream& out);

    const Skill& operator=(const Skill& aSkill);
    friend ostream& operator<<(ostream& out, const Skill& aSkill);

private:
    char* name;
    char* description;
    int level;

};

#endif
