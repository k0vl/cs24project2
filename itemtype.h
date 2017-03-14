#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class File
{
	public:
		File( string filename, int count = 1, File* next = NULL );
		string filename;
		int count;
		File* next;
};
#endif