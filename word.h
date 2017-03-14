#ifndef WORD_H
#define WORD_H
#include "itemtype.h"
using namespace std;

class Word{
	public:
		Word(string word, File* file_ptr = NULL, 
			Word* left = NULL, Word* right = NULL);
		string word;
		File* file_ptr;
		Word* left;
		Word* right;
};
#endif