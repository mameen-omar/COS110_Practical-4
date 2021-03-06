#include "global_includes.h"
#include "staff.h"

using namespace std;

Staff::Staff(string name_, Gender gender_) : Person::Person(name_, gender_)
{
}

string Staff::greet()
{
	return (getTitle() + " " + Person::greet());
}

string Staff::work()
{
	return ( this->Person::greet() + " is " + this->Person::work() + " into the Staff Portal to do some work." );
	
}

string Staff::greet(Person *other)
{
	string out;

	if(other == 0)
	{
		out = "I don't greet null people!";
		return out;
	}

	else if(recognize(other))
	{
		out = ( "Hello " + other->greet() + " we meet again. " + other->reply(this) );

		return out;
	}

	else
	{
		this->growAcquaintances();

		this->colleagues[this->getNumColleagues()] = other;

		this->numColleagues = (this->numColleagues + 1);

		out  = ( "Good day, I am " + this->greet() + " and you are? " + other->reply(this) );

		return out;
	}
	
}


string Staff::reply(Person *other)
{
	string out;

	if(other == 0)
	{
		out = "I don't greet null people!";
		return out;
	}

	else if(this->recognize(other))
	{
		out = "Hello " + other->greet() + " we meet again.";
		return out;
	}

	else
	{
		this->growAcquaintances();

		this->colleagues[this->getNumColleagues()] = other;

		this->numColleagues = (this->numColleagues + 1);

		out  = "I am " + this->greet() + ", nice to meet you " + other->greet() + ".";
		
		return out;
	}
	
}

string Staff::getTitle()
{
	if(this->getGender() == Person::male)
	{
		return "Mr";
	}

	else
	{
		return "Ms";
	}
}

