#ifndef BACKWARDS_H
#define BACKWARDS_H

#include <string>
#include "filter.h"
#include <iostream>


using namespace std;

class backwards: public filter
{
	protected:
		//No Protected Members

	private:
		//No Private Members
		
	public:
		virtual string print(string s);
};
//u16055323 - Mohamed Ameen Omar
#endif