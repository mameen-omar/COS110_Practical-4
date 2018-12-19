#include "global_includes.h"
#include "learning_machine.h"
#include <string>

using namespace std;

LearningMachine::LearningMachine(double proficiency_)
{
	proficiency = proficiency_;
}

double LearningMachine::normalizeProficiency()
{
	if(this->proficiency > 100)
	{
		this->proficiency = 100;
		return this->proficiency;
	}

	else if(this->proficiency < 0)
	{
		this->proficiency = 0;
		return this->proficiency;
	}
	
	return this->proficiency;
}

double LearningMachine::getProficiency()
{
	return this->proficiency;
}