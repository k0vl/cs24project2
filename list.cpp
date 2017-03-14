// Implementation file for Unsorted.h
#include <iostream>
#include <string>
#include "itemtype.h"
#include "word.h"
using namespace std;
void insert_file(Word* word_ptr, string filename)
{
	if( !(word_ptr->file_ptr) )
	{
		word_ptr->file_ptr = new File(filename,1,NULL);
		return;
	}
	File* iterator = word_ptr->file_ptr;
	while(iterator->filename != filename && iterator->next)
		iterator = iterator->next;
	if(iterator->filename == filename)
		iterator->count = iterator->count+1;
	else
		iterator->next = new File(filename,1,NULL);
}

Word* insert_word(Word*& node, string search)
{
	if (!node){
		node = new Word(search);
		return node;
	}
	else if (node->word == search)
		return node;
	else if(search < node->word)
		return insert_word(node->left, search);
	else
		return insert_word(node->right, search);
}

Word* find_word(Word*& node, string search)
{
	if (!node)
		return NULL;
	else if (node->word == search)
		return node;
	else if(search < node->word)
		return insert_word(node->left, search);
	else
		return insert_word(node->right, search);
}

void print_all(Word* head)
{
	//stub
}