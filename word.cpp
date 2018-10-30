#include "word.h"
#include <iostream>
using namespace std;

//Constructor
word::word(string keyword, string fname){
	this-> keyword = keyword;
	files_word -> add(fname);
}

void word::modification(string fname){
	files_word -> add(fname);
}

string word::getWord() const{
	return keyword;
}

string word::getFilename() const{
	return fname;
}

bag word::getFiles_word() const{
	return *files_word;
}
 
