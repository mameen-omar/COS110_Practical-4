#ifndef TITLECASE_H
#define TITLECASE_H

#include <string>
#include <iostream>
#include "filter.h"

using namespace std;

class titleCase: public filter
{
	protected:
		//NON

	private:
		//NON
		
	public:
		virtual string print(string s);
};

#endif