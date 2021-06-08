#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <class dtype>
class linked_queue
{
  private:
    struct node {
      dtype data;
      node * next = NULL;
    };
    int length = 0;
    node * pfirst = NULL; // pointer to the first
    node * plast = NULL; // pointer to the last
    
  public:
    // constructor
    linked_queue(dtype value)
    {
      node * temp = new node;
      temp -> data =  value;
      plast = temp;
      pfirst = temp;
      length++;
    }

    bool isEmpty ()
    {
      bool answer = false;;
        if(plast == NULL && pfirst == NULL)
          answer = true;
    
      return answer;
    }

    int enqueue(dtype value)
    {
      node * temp = new node;
      temp -> data = value;

      if(isEmpty())
      {
        pfirst = temp;
        plast = temp;
        length++;
      }
      else {
        plast -> next = temp;
        plast = temp;
        length++;
      }

      return length;
    }

    int dequeue()
    { 
      if (isEmpty())
        cout << "the queue is empty";
      else
      {
        node * item_after_first = pfirst -> next;
        delete pfirst;
        pfirst = item_after_first;
        length--;

        if (length == 0)
        {
          pfirst = NULL;
          plast = NULL;
        }
      }

      return length;
    }

    void view_queue()
    {
      node * temp = pfirst;
      int i = 0;

      while (temp != NULL)
      {
        i++;
        cout << i << ": " << temp -> data << endl;
        temp = temp -> next; 
      }
    }

    dtype peek()
    {
      return pfirst -> data;
    }
};

int main()
{
  linked_queue<string> my_queue ("ezio");
  my_queue.dequeue();
  my_queue.dequeue();
  cout << endl;
  my_queue.enqueue("giovanni");
  my_queue.enqueue("marco");
  my_queue.dequeue();
  my_queue.view_queue();
  return 0;
}