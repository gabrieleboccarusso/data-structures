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

    // note: iterative insertion into a binary tree,
    // may be more efficient using recursion
    void insert (int number)
    {
      // beginning from the root node
      node * ptr = root;
      bool insert = false;

      // while it is not inserted
      while(!insert)
      {
        // if is greater than root
        if (number > ptr -> data)
        { // if there is no node
          if (ptr -> right == NULL)
          { // create node, assign value and exit loop
            ptr -> right = new node;
            ptr -> right -> data = number;
            insert = true; 
          }
          else
          { //  otherwise we go deep one level
            ptr = ptr -> right;
          }
        }
        // same things for the left
        else if(number < ptr -> data)
        {
          if (ptr -> left == NULL)
          {
            ptr -> left = new node;
            ptr -> left -> data = number;
            insert = true;
          }
          else
          {
            ptr = ptr -> right;
          }
        }
        else 
        {
          cout << "the number os already in the tree\n or unknown error";
          insert = true;
        }
      }
    }



};

int main()
{
  tree my_tree(50);
  my_tree.insert(65);
  my_tree.insert(45);
  my_tree.insert(86);

  cout << "level 1, left node:" << my_tree.root -> left -> data;
  cout << endl;
  cout << "level 1, right node: " << my_tree.root -> right -> data;

  return 0;
}