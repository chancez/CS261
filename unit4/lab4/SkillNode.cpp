/*
 * =====================================================================================
 *
 *       Filename:  SkillNode.cpp
 *
 *         Author:  Chance Zibolski (CZ), zibolskc@onid.orst.edu
 *
 * =====================================================================================
 */

#include "Skill.h"
#include "SkillNode.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

SkillNode::SkillNode(): children(NULL)
{
}

SkillNode::SkillNode(Skill& aSkill): skill(aSkill), children(NULL)

{
    children = new SkillNode*[MAX_CHILDREN];
}

SkillNode::SkillNode(const SkillNode& aNode): children(NULL)
{
    skill = aNode.skill;

    this->children = new SkillNode*[MAX_CHILDREN];

    int i;
    for (i = 0; i < MAX_CHILDREN; i++)
    {
        children[i] = aNode.children[i];
    }

}

const SkillNode& SkillNode::operator=(const SkillNode& aNode)
{
    if (this == &aNode)
        return *this;

    skill = aNode.skill;

    if (children)
        delete [] children;

    *this->children = new SkillNode[MAX_CHILDREN];

    int i;
    for (i = 0; i < MAX_CHILDREN; i++)
    {
        children[i] = aNode.children[i];
    }

    return *this;
}

void SkillNode::insert(SkillNode** root, const Skill& aSkill)
{
    if (! *root)
    {
        Skill mySkill(aSkill);
        *root = new SkillNode(mySkill);
    }
    else if (root)
    {
        int i;
        SkillNode *curr;
        bool inserted = false;
        for (i = 0; i < MAX_CHILDREN; i++)
        {
            //right here something is wrong..
            //when calling insert again, the value isn't properly stored in
            //the array at children[i], which is still NULL.
            curr = *root;
            curr = curr->children[i];
            if (curr == NULL)
            {
                //maybe its how curr is being passed.
                cout << aSkill;
                insert(&curr, aSkill);
                inserted = true;
                break;
            }
        }
        if (inserted != true)
        {
            //no space
            cout << "No space for adding this" << endl;
        }
    }
    cout << (*root)->children[0];
}

SkillNode* SkillNode::contains(SkillNode* root, char *name) const
{
    if (!root)
        return NULL;
    else if (root)
    {
        if (strcmp(name, root->skill.getName()) == 0)
            return root;
        else
        {
            int i;
            SkillNode *curr;
            SkillNode *temp = NULL;
            for (i = 0; i < MAX_CHILDREN; i++)
            {
                *curr = *root->children[i];
                temp = contains(curr, name);
                if (temp != NULL)
                    return temp;
            }//endfor
        }
    }
}

static void printLevelSpacers(ostream& out, int spacers)
{
    for (int i = 0; i < spacers; i++)
        out << "  ";
}

void SkillNode::display (ostream& out, SkillNode * root, int level) const
{
    if (root) {
        printLevelSpacers(out, level - 1);
        if (level)
            out << "|-";
        out << root->skill << endl;
        if (root->children[0]) {
            if (root->children[0] || children[1])
            {
                cout << "test" << endl;
                display(out, root->children[0], level + 1);
            }
            else {
                printLevelSpacers(out, level);
                out << '|' << endl;
                }
            if (root->children[1])
                display(out, root->children[1], level + 1);
            else {
                printLevelSpacers(out, level);
                out << '|' << endl;
                }
            }
        }
}

void SkillNode::display(ostream& out, SkillNode *root) const
{
    if (root)
    {
        out << root->skill.getName() << endl;

        int i;
        SkillNode *curr;
        for (i = 0; i < MAX_CHILDREN; i++)
        {
            *curr = *root->children[i];
            display(out, curr);
        }
    }
}
