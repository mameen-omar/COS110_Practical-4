#include "global_includes.h"
#include "student.h"
#include "staff.h"
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>
#include <ctype.h>
#include <cmath>

using namespace std;

Student::Student(string name_, Gender gender_) : Person::Person(name_, gender_), LearningMachine::LearningMachine(0)
{
}

string Student::greet()
{
	string out;

	out =  ( this->getTitle() + " " + this->Person::greet() );

	return out;
}

string Student::greet(Person *other)
{
	string out;

	if(other == 0)
	{
		out = "I don't greet null people!";
		return out;
	}

	else if(recognize(other))
	{
		out = "Hey dude, " + other->greet() + " nice to see you again. " + other->reply(this);
		return out;
	}

	else
	{
		this->growAcquaintances();

		this->colleagues[this->getNumColleagues()] = other;

		this->numColleagues++;

		out  = "Hey dude, name's " + this->greet() + " what's yours? " + other->reply(this);

		return out;
	}
}

string Student::work()
{
	string out;

	out = this->Person::greet() + " is " + this->Person::work() + " into the Student Portal to do some work.";

	return out;
}

string Student::getTitle()
{
	if(getGender() == Person::male)
	{
		return "young";
	}

	else
	{
		return "innocent";
	}
}

string Student::reply(Person *other)
{
	string out;
	
	if(other == 0)
	{
		out = "I don't greet null people!";
		return out;
	}

	else if(this->recognize(other))
	{
		out = "Hey dude, nice to see you again " + other->greet();
		return out;
	}

	else
	{
		this->growAcquaintances();

		this->colleagues[ this->getNumColleagues() ] = other;

		this->numColleagues++;

		out  = "Hi " + other->greet() + ", " + this->Person::greet() + "'s the name.";

		return out;
	}
}

string Student::teach(Person *student)
{
	string out;

	out = (this->greet(student) + ". Um, let's start *cough*  (Student teaches). " + dynamic_cast<LearningMachine*>(student)->learn(this) + " Maybe I shouldn't teach :(");
	return out;
}

string Student::learn(Person *teacher)
{
	double prof1 = this->proficiency;

	this->proficiency = (this->proficiency) + (1.1 * ( dynamic_cast<LearningMachine*>(teacher)->getSomeProficiency() ));

	double prof2 = this->normalizeProficiency();
	
	string prof1String = static_cast<ostringstream*>( &(ostringstream() << prof1) )->str();
	
	string prof2String = static_cast<ostringstream*>( &(ostringstream() << prof2) )->str();
	
	string out = this->greet() + "'s Proficiency went from " + prof1String + " to " + prof2String + ".";
	return out;
} 

double Student::getSomeProficiency()
{
	double out = -(10.0 / (sqrt(getProficiency()) + 1) );
	return out;
}