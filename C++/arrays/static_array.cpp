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

    /*
      def view_array(self):
    i: int = 0
    for i in range(self.length):
      print(f'{i}: ', self.data[i])
    return self.length # O(n)
    */
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
  static_array<int, 5> arr;

  // cout << arr.length << endl;

  arr.push(11);
  arr.push(22);

  arr.view_array();
 
  return 0;
}