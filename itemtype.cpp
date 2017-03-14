#include "itemtype.h"
#include <iostream>
#include <cstdlib>

using namespace std;
File::File( string filename, int count, File* next )
{
	this->filename = filename;
	this->count = count;
	this->next = next;
}