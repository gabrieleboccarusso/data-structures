#include <iostream>

using std::cout;
using std::endl;

template <class dtype>
class dynamic_array
{
  public:
    int max = 1;
    int length = 0;
    dtype * data = new dtype [max]; // we begin with just one space

  int push(dtype item) 
  {
    if (length + 1 <= max)
    {
      data[length] = item;
      length++;
    }
    else 
    {
      double_spaces();
      push(item);
    }

    return length;
  }

  void double_spaces()
  {
    dtype dummy_arr[max];
    int i;

    for (i = 0; i < length; i++)
    {
      dummy_arr[i] = data[i];
    }

    // strangely enough, deleting the data
    // was resulting in an error, I'll still keep the
    // line, commented out, for any possible problem
    // with data that should have been deleted
    //delete [] data;
    max = max * 2;
    dtype * data = new int [max];
    // cout << "doubling spaces...\n";
    for (i = 0; i < length; i++)
    {
      data[i] = dummy_arr[i];
      //cout << data[i] << "\n";
    }

  }
};

int main() 
{ 
  dynamic_array<int> class_arr;

  class_arr.push(11);
  class_arr.push(22);
  class_arr.push(33);
  class_arr.push(44);
  class_arr.push(55);
  class_arr.push(66);
  class_arr.push(77);
  class_arr.push(88);
  class_arr.push(99);


  
  cout << "length now: " << class_arr.length << endl;
  for (int i; i < class_arr.length; i++)
  {
    cout << i << ": " << class_arr.data[i] << endl;
  }
  cout << "max: " << class_arr.max;
  
  return 0;
}