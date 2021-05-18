#include <iostream>

using std::cout;
using std::endl;

class tree
{
  private:
    struct node {
      int data;
      node * left;
      node * right;
    };
    int height;
    node * root;
    node * ptr = root;
 public:
    // constructor
    tree (int value)
    {
      root = new node;
      root -> data = value;
      root -> right = NULL;
      root -> left = NULL;
    }

    // note: iterative insertion into a binary tree,
    // may be more efficient/readable using recursion
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
            ptr = ptr -> left;
          }
        }
        else 
        {
          cout << "the number is already in the tree\n or unknown error";
          insert = true;
        }
      }

      return;
    }

    node* lookup(int number)
    {
     bool found = false;
     node * ptr = root;
     node* ret_ptr;

     while(ptr) // while ptr isn't NULL
     {
       if (number == ptr -> data)
        {
          found = true;
          ret_ptr = ptr;
          ptr = NULL; // exit the loop
        }
      else if(number > ptr -> data)
      {
        ptr = ptr -> right;
      }
      else if(number < ptr -> data)
      {
        ptr = ptr -> left;
      }
     }
     return ret_ptr;
    }

    node * get_root()
    {
      return root;
    }

    void delete_node(int number)
    {
      node * node_to_del = lookup(number);
      if (!(node_to_del -> right) && !(node_to_del -> left))
      {
        //cout << " this node has not children";
        delete node_to_del;
        node_to_del = NULL;
      }
      else{
        cout << "it has children";
      }
    }
};

int main()
{
  tree my_tree(9);
  my_tree.insert(4);
  my_tree.insert(20);
  my_tree.insert(1);
  my_tree.insert(6);
  my_tree.insert(15);
  my_tree.insert(170);

  my_tree.delete_node(170);
  // if we try this operation on a non-existent node 
  // it will give a segmentation error
  if(my_tree.lookup(170))
  {
    cout << "the node exist";
  }
  else
  {
    cout << "the node doesn't exists";
  }

  return 0;
}