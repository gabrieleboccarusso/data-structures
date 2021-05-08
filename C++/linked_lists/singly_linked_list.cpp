#include<iostream>

using std::cout;
using std::endl;

struct node
{
  int data;
  node * next = NULL;
};

class list
{
  private:
    node * ptail;
    node * phead;
    int length = 1;

  public:
    // constructor
    list(int data) 
    {
       node * temp = new node;
       temp -> data = data;
       ptail = temp;
       phead = temp;
    }

    // return a pointer to the tail node
    node* get_tail()
    {
      return ptail;
    }

    void append(int value)
    {
      node * temp = new node;
      phead -> next = temp;
      temp -> data = value;
      phead = temp;
      length++;
      return;
    }

    void prepend(int value)
    {
      node * temp = new node;
      temp -> data = value;
      temp -> next =ptail;
      ptail = temp;
      length++;
      return;
    }

    node* get_head()
    {
      return phead;
    }

    int get_length()
    {
      return length;
    }

    void view_list()
    {
      node *ptr = ptail;
      int i;

      for (i = 0; i < length; i++)
      {
        cout << i << ": " << ptr -> data << endl;
        ptr = ptr -> next;
      }
    }

    void insert(int index, int value)
    {
      node * ptr = get_value_at(index - 1);
      node * temp = new node;
      temp-> next = ptr -> next;
      temp -> data = value;
      ptr -> next = temp;
      length++;

      return;
    }

    node * get_value_at(int index)
    {
      node * ptr = ptail;
      int i;
      for (i = 0; i < index; i++)
      {
        ptr = ptr -> next;
      }

      return ptr;
    }

    int remove(int index)
    {
      node * ptr = get_value_at(index - 1);
      node * node_to_delete = ptr -> next;
      ptr -> next = ptr -> next -> next;
      delete node_to_delete;
      length--;
      return length;
    }


};

int main()
{
  list my_list (10);
  my_list.append(15);
  my_list.append(20);
  my_list.prepend(5);

  my_list.view_list();
  //cout << "length: " << my_list.get_length() << endl;
  cout << "deleted 1: \n";
  my_list.remove(1);
  my_list.view_list();

  return 0;
}