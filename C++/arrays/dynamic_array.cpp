#include <iostream>

using std::cout;
using std::endl;

template <class dtype>
class dynamic_array
{
  private:
    int max = 1;
  public:
    int length = 0;
    dtype * pointer = new dtype [max]; // we begin with just one space

  void something()
  {
    *pointer = 11;
    cout << "first item: "<< *pointer;
  }

  int push(dtype item)
  {
    int ret_length = length;

    if (length + 1 > max)
    {
      // double max
    }
    else
    {
      *pointer = item;
      pointer ++;
      length++;
      ret_length = length;
    }

    return ret_length;
  }

};

int main() 
{ // trying to modify an array with pointer
  /*int * ptr = new int [1];
  *ptr = 11;
  cout << "first item: " << *ptr;

  int new_arr[2];
  new_arr[0] = 22;
  new_arr[1] = 33;

  delete[] ptr;
  ptr = new_arr;
  cout << "\nsecond item: " << *ptr;
  ptr++;
  cout << "\nthird item: " << *ptr << endl;
  */
  dynamic_array<int> class_arr;
  class_arr.push(11);
  //cout << class_arr.pointer;

  return 0;
}