#include "word.h"
#include "itemtype.h"
using namespace std;


Word::Word(string word, File* file_ptr = NULL, Word* left = NULL, Word* right = NULL)
{
	this->word = word;
	this->file_ptr = file_ptr;
	this->left = left;
	this->right = right;
}