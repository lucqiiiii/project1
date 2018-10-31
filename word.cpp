//Qi Guo Project1
#include "word.h"
#include <iostream>
using namespace std;

//Constructor
word::word(unsigned int initial_capacity){
	capacity = initial_capacity;
	used = 0;
	wordlist = new string[initial_capacity];
	files_word = new bag[initial_capacity];
}

void word::add_word(string word, string filename){
	if(used > capacity){
		cout << "Maximum capacity "<<capacity<< " reached."<<endl;
		return;
	}
	unsigned int i = 0;
	for(i = 0; i < used; i++){
		if(wordlist[i] == word){
			files_word[i].add(filename);
		}
	}	
	if(i == used){
		wordlist[used] = word;
		files_word[used].add(filename);
		used++;
	}
}

int word::get_information(string word) const {
  for(unsigned int i = 0; i < used; i++){
  	if(wordlist[i] == word){
  		cout << "\nHere are the information for " << word << ":\n";
  		if(files_word[i].size() == 1){
  			cout << "There is 1 file that contains "
  			<< word << ".\n";
  			files_word[i].print();
  		}
  		else{
			cout << "There are " << files_word[i].size()
			<< "files that contain " << word << ".\n";
			files_word[i].print();
		}
	return 0;
	}
  }
  cout << "\nThere is no file that contains " << word << ".\n";
  return 0;
}





 
