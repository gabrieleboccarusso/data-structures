#include <iostream>

using std::cout;
using std::endl;

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
      plast -> next = temp;
      plast = temp;
      length++;

      return length;
    }

    int dequeue()
    {
      node * item_after_first = pfirst -> next;
      delete pfirst;
      pfirst = item_after_first;
      length--;

      return length;
    }

    void view_queue()
    {
      node * temp = pfirst;
      int i;

      while (temp != NULL)
      {
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
  linked_queue<std::string> my_queue ("primo");
  my_queue.enqueue("secondo");
  my_queue.enqueue("terzo");
  cout << "the queue:\n";
  my_queue.view_queue();
  cout << "now enqueued:\n";
  my_queue.dequeue();
  my_queue.dequeue();
  my_queue.enqueue("quarto");
  my_queue.view_queue();
  cout << "last item: " << my_queue.peek();
  return 0;
}