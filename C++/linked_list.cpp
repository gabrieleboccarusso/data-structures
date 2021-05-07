#include<iostream>

using std::cout;
using std::endl;

/* note:
  node n, n2;
  n.ptr = &n2;
  n2.data = 10;
  cout << n.ptr->data; // 10
*/

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
    //cout << my_list.ptail -> data;

  public:
    // constructor
    list(int data) 
    { // the constructor create the first node
       node * temp = new node;
       temp -> data = data;
       //cout << temp->data;
       //temp -> next = nullptr;
       ptail = temp;
       //cout << ptail->data;
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


};

int main()
{
  list my_list (10);
  my_list.append(15);
  my_list.append(20);
  my_list.prepend(5);
  node * n  = my_list.get_head();

  cout << "before preprend: " << endl;
  cout << "head data: " << n -> data << endl;
  n = my_list.get_tail();
  cout << "tail data: " << n -> data << endl;
  n = n -> next;
  cout << "data after tail: " << n -> data << endl;
  cout << "length: " << my_list.get_length() << endl;

  



  return 0;
}