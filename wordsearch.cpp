#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
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
  string dir; //
  vector<string> files = vector<string>();
  word *wordlist[1000];
  int used = 0;
  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  

  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue; //skip hidden files
    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolute path
    // ...read the file...
    string keyword;
    while(true){
      fin>> keyword;
      if(fin.eof()) {cout << "EOF " << files[i] << endl; break;}
      else {
	cout<<files[i]<<"::"<< keyword <<endl;
	
	// Now the string "keyword" holds the keyword, and the string "files[i]" holds the document name.
	// Use these two strings to search/insert in your array/list of 
	if(used > 1000){
		cout << "Maximum word storage reached." << endl;
	}
	else{
		unsigned int j = 0;
		for(j = 0; j < used; j++){
			if(wordlist[j].getWord() == keyword){
				wordlist[j].modification(files[i]);
				break;
			}
		}
		if(j == used){
			word a(keyword,files[i]);
			used ++;		
			wordlist[used] = a;
		}
      }
    }
    fin.close();
  }
  cout << "This is the next part of the program " << endl;
  string input;
  cout << "Enter a word you want to search:" << endl;
  cin >> input; 
  for( unsigned int i = 0; i < used; i++){
	if(wordlist[i].getWord() == input){
  		wordlist[i].getFiles_word().print();
	}
  }
}
}

