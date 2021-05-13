/*attempt at implementing circolar queue in cpp
from scratch */

#include <iostream>

using std::cout;
using std::endl;

template <class dtype, int size>
class static_queue
{
  private:
    int max = size;
    dtype data[size];
    int length = 0;
    int lastItem = 0; // pointing at last item, same as length
    int firstItem = 0; // pointing at the first item
  public:
    // constructor
    static_queue (dtype value)
    {
      data[firstItem] = value;
      lastItem++;
      length++;
    }

    int enqueue(dtype value)
    {
      data[lastItem] = value;
      length++;

      return length;
    }

    void view_queue()
    {
      int i;

      for (i = firstItem; i <= lastItem; i++)
      {
        cout << data[i] << endl;
      }
    }

    int dequeue()
    {
      data[firstItem] = '\0';
      length--;
      firstItem++;

      return length;
    }

    dtype peek()
    {
      return data[lastItem];
    }
};

int main()
{
  static_queue<int, 5> my_queue (5);
  my_queue.enqueue(10);
  my_queue.enqueue(15);
  my_queue.dequeue();
  cout << my_queue.peek();

  return 0;
}