#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "list.h"
#include "wordsearch.h"

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files) {
	DIR *dp;
	struct dirent *dirp;
	if((dp  = opendir(dir.c_str())) == NULL) {
		cout << "Error(" << errno << ") opening " << dir << endl;
		return errno;
	}

	while ((dirp = readdir(dp)) != NULL) {
		files.push_back(string(dirp->d_name));
	}
	closedir(dp);
	return 0;
}

int main(int argc, char* argv[])
{
	string dir;
	vector<string> files = vector<string>();
	Word* head = NULL;

	if (argc < 2) {
	  cout << "No Directory specified; Exiting ..." << endl;
	  return(-1);
	}

	dir = string(argv[1]);
	if (getdir(dir,files)!=0) {
		cout << "Error opening " << dir << "; Exiting ..." << endl;
		return(-2);
	}

	for (unsigned int i = 0; i < files.size(); i++) {
		if(files[i][0]=='.') continue; //skip hidden files
		cout << "reading " << files[i] << "...";
		ifstream fin((string(argv[1])+ "/" +files[i]).c_str()); //open using absolute path

		// ...read the file..
		string word;
		while(fin >> word)
			insert_file(insert_word(head, word), files[i]);
		fin.close();
		cout << "done" << endl;
	}

	string mode;
	string keyword;
	cout << "\nWelcome to The Dictionary\n";
	while ( mode != "exit" ) {
		cout << "Please enter a mode (Or exit to quit the program):\n";
		cout << "(1) Search\n";
		cout << "(2) Sort\n";
		cout << "Input: ";
		cin >> mode;
		mode = mode.tolower();
		if ( mode == "1" ) {
			doSearch();
		}
		else if ( mode == "2" ) {
			doSort();
		}
	}
	cout << "\nThank you for using. Have a nice day." << endl;
	return 0;
}

void doSearch() {
	while(keyword != "exit") {
		cout << "\nEnter word (Or exit to quit the mode): ";
		cin >> keyword;
		if (keyword != "exit") {
			Word* iterW = find_word(head, keyword);
			if (iterW != NULL) {
				cout << endl;
				File* iterF = iterW->file_ptr;
				while (iterF != NULL) {
					cout << iterF->filename << "         " << iterF->count << endl;
					iterF = iterF->next;
				}
				cout << "WordTotal     " << iterW->wordTotal;
				cout << "FileTotal     " << iterW->fileTotal;
				cout << "Average       " << iterW->wordTotal/iterW->fileTotal;
				cout << endl << endl;
			}
		}
	}
}

void doSort() {

}



