/**
Program to reverse a string (char *) recursively.

@Author Ankit Singh, 2014 
@Copyright devGeeks Lab
*/

#include <iostream>
#include <string>
using namespace std;

char * reverse_s(char *, char*, int,int);

int main(int argc, char** argv) {
  if(argc != 2) {
    cout << "\n ERROR! Input String";
    cout << "\n\t " << argv[0] << "STRING" << endl;
    return 1;
  }
  char* str = new char[strlen(argv[1])+1];
  strcpy(str,argv[1]);
  char* rev_str = new char[strlen(str)+1];
  cout<<"\n\nFinal Reverse of '" << str << "' is --> "<< reverse_s(str, rev_str, 0, strlen(str)) << endl; 
  cin.ignore();
  delete rev_str, str;
  return 0;
}

char* reverse_s(char* str, char* rev_str, int str_index, int rev_index ) {
  
  if(strlen(str) == 1) 
    return str;
  
  if(str[str_index] == '\0' ) {
    rev_str[str_index] = '\0';
    return rev_str;
  }
  
  str_index += 1;
  rev_index -=1;
 
  rev_str = reverse_s(str, rev_str, str_index, rev_index);
  
  if(rev_index >= 0) {
    cout << "\n Now the str value is " << str[str_index-1] << " -- Index " << str_index << " Rev Index: " << rev_index; 
    rev_str[rev_index] = str[str_index-1];
    
    cout << "\nReversed Value: " << rev_str << endl;
  }
  return rev_str;
}
