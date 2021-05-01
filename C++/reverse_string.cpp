#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int main() 
{
  // create array of characters, max 50
  char str[50];
  int i; // iterator for both fors
  int j = 0; // iterator for saving the string in another array
  int size = 0; // size of the string

  // ask the string to the user
  cout << "enter the string to reverse: ";
  cin >> str;

  // first of all we have to find the size of the string,
  // and we can do it with a for loop
  for (i = 0; str[i]; i++)
  {
    size++;
  }
  
  // looping backwards, from the size till zero, we can print the string
  cout << "the reversed string: ";
  for (i = size -1; i >= 0; i--) 
  {
    cout << str[i];
  }

  cout << endl;

  // just printing a reversed string is useless, at least we would like
  // to save it into a variable, or in this case in an array of chars,

  // create the second array of char
  char rev_str[size];
  // loop through the string backwards
  for (i = size - 1; i >= 0; i--) 
  {
    // j begin from zero and increase at every interaction,
    // this was the originally string goes backwards while
    // while the reversed goes onward
    rev_str[j] = str[i];
    j++;
  }

  // create last string with every character reversed
  string final_string;
  final_string.assign(rev_str, size);
  cout << "now saved in an variable: " << final_string;

 return 0;
}