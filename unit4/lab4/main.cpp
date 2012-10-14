#include <iostream>
#include "SkillTree.h"

#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

using namespace std;

void TestSkillTree()
{
	// Student skills 

	SkillTree student("Student");
	student.Display(cout);

	student.AddSkill("Alphabet","Mastery of letters and sounds",0);
	student.Display(cout);

	student.AddSkill("Reading","The ability to read all manner of written material",1,"Alphabet");
	student.AddSkill("Writing","The ability to put your thoughts on paper",1,"Alphabet");
	student.Display(cout);

	student.AddSkill("Speed Reading Level 1","Read any text twice as fast as normal",5,"Reading");
	student.AddSkill("Speed Reading Level 2","Read any text four times as fast as normal",10,"Speed Reading Level 1");
	student.AddSkill("Memorization","Memorize average sized texts",10,"Reading");
	student.AddSkill("Massive Memorization","Memorize large sized texts",20,"Memorization");
	student.AddSkill("Spell Writing","The ability to write spells",5,"Writing");
	student.AddSkill("History","The ability to write (and rewrite) history",10,"Writing");
	student.AddSkill("Written Creation","The ability to write things into reality",20,"History");
	student.Display(cout);

	// Warrior skills
	SkillTree warrior("Warrior");
	warrior.AddSkill("Basic Training","Basic training and conditioning",0);
	warrior.AddSkill("Hand To Hand","The fundamentals of hand to hand combat",3,"Basic Training");
	warrior.AddSkill("Grappling","Learn the most common wrestingling moves and holds",10,"Hand To Hand");
	warrior.AddSkill("Marial Arts","Learn devestating hand to hand techniques based on ancient eastern arts",10,"Hand To Hand");
	warrior.AddSkill("Weapons","The beginning skill for all weapons",5,"Basic Training");
	warrior.AddSkill("Sword","Fundamentals of sharp metal things",10,"Weapons");
	warrior.AddSkill("Staff","Fundamentals of hard wooden sticks",10,"Weapons");
	warrior.AddSkill("Bow","Fundamentals of using a bow and arrow",10,"Weapons");
	warrior.Display(cout);

	// Now try adding stuff that doesn't belong

	student.AddSkill("Spitballs","The clever art of making and projecting spitballs",20,"Bully");
	student.Display(cout);

	// Now try adding a new root

	warrior.AddSkill("Physical Conditioning","Training in strength, flexibility, agility, and balance",0);
	warrior.Display(cout);

	// Now try adding too many children
	warrior.AddSkill("Energy Weapons","The use of energy weapons such as lasers.",20,"Weapons");
	warrior.Display(cout);

	// Finally, looks up some skills
	Skill* sk;
	sk = student.FindSkill("Reading");
	if (sk != NULL) {
		cout << "Found the skill" << endl;
		sk->Display(cout);
		cout << endl;
	} else {
		cout << "Not found" << endl;
	}
}

int main() {

	TestSkillTree();

#ifdef _WIN32
	if (_CrtDumpMemoryLeaks()) {
		cout << "Memory leaks!" << endl;
	}
#endif

	return 0;
}
