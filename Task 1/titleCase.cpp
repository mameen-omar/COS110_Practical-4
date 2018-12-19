#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include "titleCase.h"

using namespace std;

string titleCase::print(string s)
{

	size_t length = s.length();

	char letter;

	size_t lower = 0;


	while (lower < length)
	{
		letter = s[lower];
		if( isalpha(letter) )
			s[lower] = tolower(letter);
		
		lower++;
	}
	
	bool capital = true;

	for(size_t x = 0; x <= length; x++)
	{
		if (isalpha(s[x]) && capital == true)
		{	
			s[x] = toupper(s[x]);	
			capital = false;
		}

		else if (isspace(s[x]))
			capital = true;
	}
	
	// beginning sentence										//u16055323 - Mohamed Ameen Omar

	
	
	if(s.find("The ", 0) == 0)
	{
		s[0] = 't';
	}
	
	if(s.find("A ", 0) == 0)
	{
		s[0] = 'a';
	}

	if(s.find("And ", 0) == 0)
	{
		s[0] = 'a';
	}	
	
	size_t index = 0;		
	
	//Look for The
	size_t the = s.find(" The ", index);

	if(the != -1)
	{
		while(the != -1)
		{
			index = the;
			s[the + 1] = 't';
			the = s.find(" The ", index);
		}
	}

	index = 0;
														//u16055323 - Mohamed Ameen Omar

	// Look for And
	size_t And = s.find(" And ", index);

	if(And != -1)
	{
		while(And != -1)
		{
			index = And;
			s[And + 1] = 'a';
			And = s.find(" And ", index);
		}
	}
	
	index = 0;

	//Look for A
	size_t a = s.find(" A ", index);
															//u16055323 - Mohamed Ameen Omar
	if(a != -1)
	{
		 while(a != -1)
		{
			index = a;

			s[a + 1] = 'a';

			a = s.find(" A ", index);
		}
	}
	
	return s;
}

													//u16055323 - Mohamed Ameen Omar