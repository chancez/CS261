/*
 * =====================================================================================
 *
 *       Filename:  SkillNode.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#ifndef SKILLNODE_H
#define SKILLNODE_H

#include "Skill.h"
#include <ostream>

class SkillNode
{
public:
    SkillNode();
    SkillNode(const SkillNode& aNode);
    SkillNode(Skill& aSkill);
    //~SkillNode();

    void insert(SkillNode** root, const Skill& aSkill);
    SkillNode* contains(SkillNode* root, char *name) const;
    void display(ostream& out, SkillNode *root) const;
    void display (ostream& out, SkillNode * root, int level) const;

    const SkillNode& operator=(const SkillNode& aNode);


private:
    Skill skill;
    SkillNode **children;

    const static int MAX_CHILDREN = 3;
};

#endif
