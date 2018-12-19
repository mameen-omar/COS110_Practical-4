#include "global_includes.h"
#include "person.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include "global_includes.h"
#include "person.h"

using namespace std;

size_t Person::empNoCounter = 12345678;

Person::Person(std::string name_, Person::Gender gender_)
{
	this->name = name_ ;

	this->numColleagues = 0;

	this->gender = gender_ ;
	
	this->empNo = empNoCounter++ ;

	this->colleagues = 0;
}

Person::~Person()
{
	
	delete [] colleagues;

	colleagues = 0;
}

size_t Person::getNumColleagues()
{
	return numColleagues;
}

string Person::work()
{
	ostringstream strmString;

	strmString << "logging in with employee number " << setw(8) << setfill('0') << empNo ;

	return ( strmString.str() );
}

Person &Person::operator[](size_t i)
{
	if(i >= 0 && i < numColleagues)
	{
		return *(colleagues[i]);
	}

}

string Person::greet()
{
	return name;
}

void Person::growAcquaintances()
{
	Person **temp = new Person*[ (numColleagues + 1) ];

	for(int index = 0; index < (this->numColleagues); index++)
	{
		temp[index] = this->colleagues[index];
	}
	
	temp[this->numColleagues] = 0;
	
	delete [] colleagues;

	this->colleagues = temp;
}

Person::Gender Person::getGender()
{
	return gender;
}

bool Person::recognize(Person *other)
{
	for(int x = 0; x < this->numColleagues; x++)
	{
		if(colleagues[x] == other)
		{
			return true;
		}
	}

	return false;
}

