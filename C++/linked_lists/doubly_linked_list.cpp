#include <iostream>

using std::cout;
using std::endl;

struct node {
  int data;
  node * next = NULL;
  node * previous = NULL;
};

class doubly_list
{
  private:
    node * ptail;
    node * phead;
    int length = 1;
  public:
    doubly_list(int value)
    {
      node * temp = new node;
      temp -> data = value;
      ptail = temp;
      phead = temp;
    }

    int append(int value)
    { // work in progress
      node * temp = new node;
      temp -> data = value;
      phead -> next = temp;
      temp -> previous = phead;
      phead = temp;
      length++;
      return length;
    }

    void view_list()
    {
      node * ptr = ptail;
      int i;
      for (i = 0; i < length; i++)
      {
        cout << i << ": " << ptr -> data << endl;
        ptr = ptr -> next;
      }

      return;
    }

    void view_list_backwards()
    {
      node * ptr = phead;
      int i;
      for (i = length - 1; i >= 0; i--)
      {
        cout << i << ": " << ptr -> data << endl;
        ptr = ptr -> previous;
      }
      return;
    }

    int prepend(int value)
    {
      node * temp = new node;
      temp -> data = value;
      temp -> next = ptail;
      ptail -> previous = temp;
      ptail = temp;
      length++;

      return length;
    }
    
};

int main()
{
  doubly_list my_list(15);
  my_list.append(20);
  my_list.append(25);
  // my_list.view_list();
  //my_list.view_list_backwards();
  my_list.prepend(10);
  my_list.view_list_backwards();

  return 0;
}