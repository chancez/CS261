/*
 * =====================================================================================
 *
 *       Filename:  SkillTree.h
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#ifndef SKILLTREE_H
#define SKILLTREE_H

#include "Skill.h"
#include "TreeNode.h"

class SkillTree
{
public:
    SkillTree();
    SkillTree(char *title);
    SkillTree(const SkillTree& aSkillTree);
    ~SkillTree();

    void AddSkill(char* name,char* desc,int level);
    void AddSkill(char* name,char* desc,int level,char* parentName);
    Skill* FindSkill(char* name);
    void Display(ostream& out);

private:

    const int MAX_CHILDREN = 3;
    int size;
    TreeNode *root;
    char *title;


};


#endif
