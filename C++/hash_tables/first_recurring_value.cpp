//Google Question
//Given an array = [2,5,1,2,3,5,1,2,4]:
//It should return 2

//Given an array = [2,1,1,2,3,5,1,2,4]:
//It should return 1

//Given an array = [2,3,4,5]:
//It should return undefined
#include <iostream>
#include <map>

using std::endl;
using std::cout;
using std::map;
using std::string;

string recurring_val(int arr[], int length);

int main()
{
  int arr1 [10] = {2,5,1,2,3,5,1,2,4};
  int arr2 [10] = {2,1,1,2,3,5,1,2,4};
  int arr3 [4] = {2,3,4,5};
  int length = 10;

  cout << recurring_val(arr1, length) << endl;
  cout << recurring_val(arr2, length) << endl;
  length = 4;
  cout << recurring_val(arr3, length) << endl;

  return 0;
}

string recurring_val(int arr[], int length)
{
  map<int, int> ht; // hash table

  // loop through the array
  int i;
  int ret_value = 0;
  bool found = false;
  for (i = 0; i < length; i ++)
  {
    // if item in hash table
    if (ht[arr[i]])
    {
      // found
      found = true;
      ret_value = arr[i];
      break; // spaghetti code
    }
    // otherwise add elemento to hash table
    else
    ht[arr[i]] = arr[i];
  }
  
  string ret_str;
  if (found)
  {
    ret_str = std::to_string(ret_value);
  }
  else 
  {
    ret_str = "undefined";
  }

  return ret_str;
}