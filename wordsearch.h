#ifndef WORDSEARCH_H
#define WORDSEARCH_H
#include <vector>
#include <string>

using namespace std;

int getdir (string dir, vector<string> &files);
int main(int argc, char* argv[]);
void doSearch(Word*& head);
void doSort(Word*& head);
void printNode(Word*& head, int count);
#endif



