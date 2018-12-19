#include "backwards.h"
#include <cctype>
#include <string>
#include <iostream>

using namespace std;										//u16055323 - Mohamed Ameen Omar

string backwards::print(string s)
{
	string temporary = s;

	size_t space = 0;

	size_t index = 0;

	space = s.find(" ", index);

	if(space != -1)
	{																					//u16055323 - Mohamed Ameen Omar
		while( space >= 0 && space != -1 && space < s.length() )
		{
			size_t count = 0;

			for(size_t x = index; x < space; x++)
			{
				s[x] = temporary[space - count - 1];

				count++;
			}

			index = space + 1;

			space = s.find(" ", index);
		}
		
																					//u16055323 - Mohamed Ameen Omar
		size_t count = 0;

		for(size_t x = index; x < ( s.length() ); x++)
		{
			s[x] = temporary[ (s.length() - count - 1 ) ];

			count++;
		}
	}

	else
	{
		size_t length = s.length();

		for(size_t y = 0; y < length; y++)
		{
			s[y] = temporary[ ( length - y - 1 ) ];
		}
	}

	return s;
}