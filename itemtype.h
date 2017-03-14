#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
#include <cstdlib>

using namespace std;

class File
{
	public:
		File( string str, int num, File* ptr );
		void setFilename( string str );
		void setCount( int num );
		void setNext( File* ptr );
		string getFilename() const;
		int getCount() const;
		File* getNext() const;
	private:
		string filename;
		int count;
		File* next;
};
#endif