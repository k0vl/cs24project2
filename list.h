#ifndef LIST_H
#define LIST_H
#include "itemtype.h"
using namespace std;

void insert_file(Word* word_ptr, string filename);
Word* insert_word(Word*& head, string search);
void print_all(Word* head);
#endif