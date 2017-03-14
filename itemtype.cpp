#include "itemtype.h"
#include <iostream>
#include <cstdlib>

using namespace std;
File::File( string filename, int count = 1, File* next = NULL )
{
	this->filename = filename;
	this->count = count;
	this->next = next;
}