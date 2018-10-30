#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <cstdlib>
#include "bag.h"
using namespace std;

class word{
    public:
        //Constructor
	word(string keyword, string fname);
        //Modification Member Functions
	void modification(string fname);
        //Constant Member Functions
        string getWord() const;
	string getFilename() const;
	bag getFiles_word() const;

    private:
	string keyword;
	string fname;
	bag *files_word;
};




#endif
