#include "global_includes.h"
#include "lecturer_msc.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>

using namespace std;

LecturerMsC::LecturerMsC(string name_, Gender gender_) : Staff::Staff(name_, gender_, 70)
{
}

string LecturerMsC::teach(Person *student)
{
	string out  = (this->greet(student) + " Great, let's start the lesson (LecturerMsC teaches). " + dynamic_cast<LearningMachine*>(student)->learn(this) );
	
	return  out;
}

string LecturerMsC::learn(Person *student)
{
	double prof1 = this->getProficiency();

	this->proficiency = this->proficiency + ( 1.25 *( dynamic_cast<LearningMachine*>(student)->getSomeProficiency() ));

	double prof2 = this->normalizeProficiency();
	
	string prof1String = (static_cast<ostringstream*>( &(ostringstream() << prof1) )->str() );

	string prof2String = (static_cast<ostringstream*>( &(ostringstream() << prof2) )->str() );
	
	string out = (this->greet() + "'s Proficiency went from " + prof1String + " to " + prof2String + "." );

	return out;
}

double LecturerMsC::getSomeProficiency()
{
	return 0.05 * proficiency;
}