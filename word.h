#ifndef WORD_H
#define WORD_H
#include "itemtype.h"
using namespace std;

class Word{
	public:
		Word(string str, File* ptrF, Word* ptrW);
		void setWord( string str );
		void setFilePtr( File* ptr );
		void setNext( Word* ptr );
		string getWord() const;
		File* getFilePtr() const;
		Word* getNext() const;
	private:
		string word;
		File* file_ptr;
		Word* next;
};
#endif