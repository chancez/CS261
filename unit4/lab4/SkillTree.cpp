/*
 * =====================================================================================
 *
 *       Filename:  SkillTree.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#include "Skill.h"
#include "SkillTree.h"
#include <string.h>

SkillTree::SkillTree(): root(NULL), size(0), title(NULL)
{
}

SkillTree::SkillTree(char *title): root(NULL), size(0), title(NULL)
{
    this->title = new char[strlen(title)+1];
    strcpy(this->title,title);
}

SkillTree::~SkillTree()
{
    if (this->title)
        delete [] this->title;
}
