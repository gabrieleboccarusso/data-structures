/* implementation of the stack data structure from scratch
 *  using static arrays (fixed size) */

#include <iostream>

using std::cout;
using std::endl;

template <class dtype, int size>
class static_stack
{
  private:
    dtype data[size] = { };
    int length = 0;
  
  public:
    int push(dtype value)
    {
      data[length] = value;
      length++;

      return length;
    }

    void view_stack()
    {
      int i; // possible iterator if the stack isn't empty

      if (isEmpty())
        cout << "stack empty";
      else
      {
        for (i = 0; i < length; i++)
        {
          cout << i << ": " << data[i] << endl;
        }
      }

      return;
    }

    bool isEmpty()
    {
      bool answer = false;

      if(length == 0)
        answer = true;

      return answer;
    }

    dtype peek()
    {
      return data[length - 1];
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
  static_stack<int, 5> my_stack;
  my_stack.push(5);
  my_stack.push(10);

  my_stack.view_stack();
  my_stack.pop();
  my_stack.pop();
  my_stack.view_stack();

  return 0;
}