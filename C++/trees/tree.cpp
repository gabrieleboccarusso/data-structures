#include <iostream>

using std::cout;
using std::endl;

class tree
{
  public:
    struct node {
      int data;
      node * left;
      node * right;
    };
    int height;
    node * root;
    node * ptr = root;
 // public:
    // constructor
    tree (int value)
    {
      root = new node;
      root -> data = value;
      root -> right = NULL;
      root -> left = NULL;
    }

    void insert (int number)
    {
      node * ptr = root;
      bool insert = false;

      while(!insert)
      {
        if (number > ptr -> data)
        {
          ptr -> right = new node;
          ptr -> right -> data = number;
          insert = true;
        }
        else if(number < ptr -> data)
        {
          ptr -> left = new node;
          ptr -> left -> data = number;
          insert = true;
        }
      }
    }



};

int main()
{
  tree my_tree(50);
  my_tree.insert(65);

  cout << my_tree.root -> right -> data;

  return 0;
}