// Implementation file for Unsorted.h
#include <iostream>
#include <string>
#include "itemtype.h"
#include "word.h"
using namespace std;
void insert_file(Word* word_ptr, string filename)
{
	if( !(word_ptr->getFilePtr()) )
	{
		word_ptr->setFilePtr(new File(filename,1,NULL));
		return;
	}
	File* iterator = word_ptr->getFilePtr();
	while(iterator->getFilename() != filename && iterator->getNext())
		iterator = iterator->getNext();
	if(iterator->getFilename() == filename)
		iterator->setCount(iterator->getCount()+1);
	else
		iterator->setNext (new File(filename,1,NULL));
}

Word* insert_word(Word*& head, string search)
{
	if (!head) {
		head = new Word(search,NULL,NULL );
		return head;
	}
	Word* ptr = head;
	while (ptr->getWord() != search && ptr->getNext())
		ptr = ptr->getNext();
	if (ptr->getWord() == search)
		return ptr;
	ptr->setNext(new Word(search,NULL,NULL));
	return ptr->getNext();
}

void print_all(Word* head)
{
	while(head){
		cout << "\"" << head->getWord() << "\"" << endl;
		for(File* i = head->getFilePtr(); i; i = i->getNext())
			cout << i->getFilename() << ":" << i->getCount() << endl;
		head = head->getNext();
	}
}