#include "global_includes.h"
#include "lecturer_phd.h"
#include "student.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctype.h>

using namespace std;

LecturerPhD::LecturerPhD(string name_, Gender gender_) : Staff::Staff(name_, gender_, 80)
{
}

string LecturerPhD::teach(Person *student)
{
	string out = this->greet(student) + ( " Starting the lesson now (LecturerPhD teaches). " + dynamic_cast<LearningMachine*>(student)->learn(this) );
	
	return out ;
}

string LecturerPhD::learn(Person *student)
{
	double prof1 = this->getProficiency();

	this->proficiency = this->proficiency + (1.5 * (dynamic_cast<LearningMachine*>(student)->getSomeProficiency() ));

	double prof2 = this->normalizeProficiency();
	
	string prof1String = ( static_cast<ostringstream*>( &(ostringstream() << prof1) )->str() );

	string prof2String = ( static_cast<ostringstream*>( &(ostringstream() << prof2) )->str() );
	
	string out = ( this->greet() + "'s Proficiency went from " + prof1String + " to " + prof2String + "." );

	return out;
}

double LecturerPhD::getSomeProficiency()
{
	double out = 0.1 * proficiency;
	return out;
}

string LecturerPhD::getTitle()
{
	return "Dr";
}