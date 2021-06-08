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

  int double_spaces()
  {
    dtype dummy_arr[max];
    int i;

    for (i = 0; i < length; i++)
    {
      dummy_arr[i] = data[i];
    }

    delete [] data;
    max = max * 2;
    data = new dtype [max];
    // cout << "doubling spaces...\n";
    for (i = 0; i < length; i++)
    {
      data[i] = dummy_arr[i];
      //cout << data[i] << "\n";
    }

    return max;
  }

  void view_array()
  {
    int i;
    for (i = 0; i < length; i++)
    {
      cout << i << ": " << data[i] << endl;
    }

    return;
  }
};

int main() 
{ 
  dynamic_array<float> arr;

  arr.push(1.1);
  arr.push(2.2);
  arr.push(3.3);
  arr.push(4.4);
  arr.push(5.5);
  
  cout << "length now: " << arr.length << endl;
  arr.view_array();
  cout << "max: " << arr.max;
  
  return 0;
}