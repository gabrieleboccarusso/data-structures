#include <iostream>

using std::cout;
using std::endl;

template <class dtype, int max>
class static_array
{
  /*
  Attributes:
  - length: length of the array
  - dtype: data type of the array
  - max: max size of the array
  - data: effectivate data of the static array
  Methods:
  - push(): push a new item at the end of the array
  - get_value_at(): return an item at a given index of the array
  - view_array(): view all the elements of the array
  - pop(): delete the last item of the array
  - reverse_array(): reverse the array itself, takes no arguments
  - void_array(): void the array
  */
  public:
    int length = 0;
    dtype data[max];

    // this first version doesn't need the constructor
    // due the template

    // BEGIN *push* 
    int push (dtype item)
    {
      int ret_length = length; // contains the length to return

      if (length + 1 <= max)
      {
        data[length] = item;
        length++;
        ret_length = length;
      }
      else 
      {
        cout << "sorry, index out of range";
      }

      return ret_length; // O(1)
    }
    // END *push*

    // BEGIN *get_value_at*
    dtype get_value_at(int index)
    {
      return data[index]; // O(1)
    }
    // END *get_value_at*

    void view_array()
    {
      int i;
      for (i = 0; i < length; i++)
      {
        cout << i << ": " << data[i] << endl;
      }

      return;
    }

    dtype pop()
    {
      dtype item = data[length - 1];
      length--;

      data[length] = '\0';

      return item;
    }

    void reverse_array()
    {
      int length_arr = length;
      dtype dummy_arr[length_arr];
      int i; 
      // view_array();

      // creating dummy array
      for (i = 0; i < length_arr; i++)
      {
        dummy_arr[i] = data[i];
      }

      void_array();

      // pushing all the the values of the dummy array
      // into the now voided original
      for (i = length_arr -1; i >= 0; i--)
      {
        push(dummy_arr[i]);
      }

      return; // O(n)
    }

    void void_array()
    {
      int length_arr = length;
      int i;

      for (i = 0; i < length_arr; i++)
      {
        pop();
      }

      return;
    }

};

int main()
{
  static_array<int, 5> arr;

  arr.push(11);
  arr.push(22);
  arr.push(33);

  arr.reverse_array();

  arr.view_array();

 return 0;
}