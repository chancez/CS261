/*
 * =====================================================================================
 *
 *       Filename:  Skill.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#include "Skill.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

Skill::Skill(): name(NULL), description(NULL), level(0)
{
}

Skill::Skill(char* name, char* description, int level):
    name(NULL), description(NULL), level(0)
{
    setName(name);
    setDescription(description);
    setLevel(level);
}

Skill::~Skill()
{
    if(name)
        delete [] name;
    if(description)
        delete [] description;
}

Skill::Skill(const Skill& aSkill):
    name(NULL), description(NULL), level(0)
{
    setName(aSkill.name);
    setDescription(aSkill.description);
    setLevel(aSkill.level);
}

void Skill::setName(char* name)
{
    if (this->name)
        delete [] this->name;

    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

void Skill::setDescription(char* description)
{
    if (this->description)
        delete [] this->description;

    this->description = new char[strlen(description)+1];
    strcpy(this->description, description);
}

void Skill::setLevel(int level)
{
    this->level = level;
}

char* Skill::getName()
{
    return this->name;
}

char* Skill::getDescription()
{
    return this->description;
}

int Skill::getLevel()
{
    return this->level;
}

void Skill::Display(ostream& out)
{
    out << this->getName() << endl;

}

ostream& operator<<(ostream& out, const Skill& aSkill)
{
    out << aSkill.name << endl;

    return out;
}

const Skill& Skill::operator=(const Skill& aSkill)
{
    setName(aSkill.name);
    setDescription(aSkill.description);
    setLevel(aSkill.level);

    return *this;
}

