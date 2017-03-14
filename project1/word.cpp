#include "word.h"
#include "itemtype.h"
using namespace std;


Word::Word(string str, File* ptrF, Word* ptrW)
{
	word = str;
	file_ptr = ptrF;
	next = ptrW;
}

void Word::setWord( string str )
{
	word = str;
}
void Word::setFilePtr( File* ptr )
{
	file_ptr = ptr;
}
void Word::setNext( Word* ptr )
{
	next = ptr;
}
string Word::getWord() const
{
	return word;
}
File* Word::getFilePtr() const
{
	return file_ptr;
}
Word* Word::getNext() const
{
	return next;
}