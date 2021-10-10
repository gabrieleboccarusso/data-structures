// TO DO: make the code more readeable
#include<iostream>
#include<stack>

using std::cout;
using std::endl;
using std::stack;

template<class dtype>
class stacks_queue
{
  private:
    stack<dtype> stack_one;
    int length = 0;
  public:
    int dequeue()
    {
      stack_one.pop();
      length--;

      return length;
    }

    void enqueue(dtype value)
    {
      // create stack two
      stack<dtype> stack_two;

      // reverse stack one into stack two
      while(!stack_one.empty())
      {
        stack_two.push(stack_one.top());
        stack_one.pop();
      }

      // add the value at the top of stack two
      stack_two.push(value);
      // reverse stack two into stack one again
      while(!stack_two.empty())
      {
        stack_one.push(stack_two.top());
        stack_two.pop();
      }
      

    }

    void peek()
    {
      cout << stack_one.top();
    }

};

int main()
{
  stacks_queue<int> my_crazy_queue;
  my_crazy_queue.enqueue(5);
  cout << endl;
  my_crazy_queue.enqueue(10);
  my_crazy_queue.dequeue();
  my_crazy_queue.peek();

  return 0;
}