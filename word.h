//Qi Guo Project1
#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <cstdlib>
#include "bag.h"
using namespace std;

class word{
    public:
        //Constructor: construct a string array that store all the words
        //and link that array to a bag array
	word(unsigned int initial_capacity = 0); 
        //Modification Member Functions
        //add a word in the string array wordlist and a bag in the bag array
        void add_word(string word, string filesname); 
        //Constant Member Functions
	int get_information(string word) const;

    private:
	unsigned int capacity;
	unsigned int used;
	string *wordlist;
	bag *files_word;
};




#endif
