## linked list

A linked list is a data strcture where every item (struct)of the list has pointer to the next item of the list.

Here, we have as node a simple struct with an `int` value and the pointer to the next item, initialized to NULL:
```cpp
struct node
{
  int data;
  node * next = NULL;
};
```

which well use for all the cases, although it would we pretty simple to make the data a `float` or a `char` through the use of template, but this is not needed now.

Ideally, we could use a personalized struct for all the class, something like 
```cpp
struct node {
  given_struct data;
  node * next = NULL
}
```
but I haven't find a way neither on internet for now, maybe I'll leave it as it is or shall find a way

### Attributes

In the class we have three attributes:
* `node * ptail;`: pointer to the tail of the list, the first item
* `node * phead;` pointer to the head of the list, the last item
* `int length = 1;` the length of the array, began at one because the constructor creates the first node


## doubly linked list