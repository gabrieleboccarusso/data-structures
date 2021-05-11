/* implementation of the stack data structures using dynamic arrays and dynamic memory */
#include <iostream>

using std::cout;
using std::endl;

template <class dtype>
class dynamic_stack
{
  private:
    int length = 0;
    int max = 2;
    dtype * data = new dtype [max];

  public:
    int push(dtype value)
    {
      if (length + 1 >= max)
      {
        double_size();
        push(value);
      }
      else
      {
        data[length] = value;
        length++;
      }

      return length;
    }

    void double_size()
    {
      // double max size
      max *= 2;
      // create new dynamic array 
      dtype *temp = new dtype[max];
      int i;
      for (i = 0; i < length; i++)
      { // fill the dynamic array with all the prev values of data
        temp[i] = data[i];
      }

      // delete what was pointing data
      delete[] data;
      // now data poin to temp
      data = temp;
      
      return;
    }

    void view_stack()
    {
      int i;
      for (i = length - 1; i >= 0; i--)
      {
        cout << i << ": " << data[i] << endl;;
      }

      return;
    }

    int get_max()
    {
      return max;
    }

    dtype peek()
    {
      return data[length-1];
    }

    int pop()
    {
      data[length - 1] = 0;
      length--;

      return length;
    }

};


int main()
{
  dynamic_stack<int> my_stack;
  my_stack.push(5);
  my_stack.push(10);
  my_stack.push(15);
  my_stack.pop();

  my_stack.view_stack();
  
  return 0;
}