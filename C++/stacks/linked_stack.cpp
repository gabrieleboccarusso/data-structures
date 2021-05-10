#include <iostream>

using std::cout;
using std::endl;

template <class dtype>
class linked_stack
{
  private:
    struct node {
      dtype data;
      node * previous = NULL;
    };
    node * ptop; // pointer to the top
    node * pbottom; // pointer to the bottom
    int length = 0;

  public:
    // constructor
    linked_stack(dtype set_data)
    {
      node * temp = new node;
      temp -> data = set_data;
      ptop = temp;
      pbottom = temp;
      pbottom -> previous = NULL;
      length++;
    }

    // pushing a new node at the top of the stack
    int push(dtype value)
    {
      node * temp = new node;
      temp -> data = value;
      // assign the pointer into the node the ex top
      temp -> previous = ptop;
      // set the top at the new pushed node
      ptop = temp;
      length++;;

      return length;
    }

    // return the value of the last item of the stack (the top)
    dtype peek()
    {
      return ptop -> data;
    }

    int get_length()
    {
      return length;
    }

    // view all the element of the stack
    void view_stack()
    {
      // begin from the top
      node * ptr = ptop;
      int i = length;

      while (ptr != NULL)
      {
        cout << i << ": " << ptr -> data << endl;
        ptr = ptr -> previous;
        i--;
      }

      return;
    }

    int pop()
    {
      node * to_delete = ptop;
      ptop = ptop -> previous;
      delete to_delete;
      length--;

      return length;
    }

    bool isEmpty()
    {
      bool answer = false;

      return answer;
    }
};

int main()
{
  linked_stack<int> my_stack (10);
  my_stack.pop();
  cout << my_stack.isEmpty();

  return 0;
}