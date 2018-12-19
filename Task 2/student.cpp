#include "global_includes.h"
#include "student.h"
#include <string>

using namespace std;

Student::Student(string name_, Gender gender_) : Person::Person(name_, gender_)
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