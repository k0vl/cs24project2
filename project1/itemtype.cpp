#include "itemtype.h"
#include <iostream>
#include <cstdlib>

using namespace std;
File::File( string str, int num, File* ptr )
{
	filename = str;
	count = num;
	next = ptr;
}

void File::setFilename( string str )
{
	filename = str;
}
void File::setCount( int num )
{
	count = num;
}
void File::setNext( File* ptr )
{
	next = ptr;
}
string File::getFilename() const
{
	return filename;
}
int File::getCount() const
{
	return count;
}
File* File::getNext() const
{
	return next;
}