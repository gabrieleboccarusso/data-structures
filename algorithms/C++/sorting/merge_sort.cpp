// this code is incomplete
#include <iostream>

using std::cout;
using std::endl;

int* merge_sort(int *ptr, int size);
void merge(int *left, int*right, int left_size, int right_size);

int main()
{
  int size = 4;
  int arr[] = {9, 0, 2, 1};
  int *ptr = arr;

  merge_sort(arr, size);

  for(int i = 0; i < size; i++)
  {
    cout << ptr[i] << " ";
  }

  return 0;
}

// in those first cases we'll not take in consideration
// that size may be a non-pair number
int* merge_sort(int *ptr, int size)
{
  int i;
  int half_size = size/2;
    int *left = new int[half_size];
    int *right = new int [half_size];
    int outer_counter = 0;
  // else if size is greater than 1
  if (size > 1)
  { // create two array with half the size

    // fill the two arrays
    for (i = 0; i < half_size; i++)
      left[i] = ptr[i];


    for (i = half_size; i < size; i++)
    {  
      right[outer_counter] = ptr[i];
      outer_counter++;
    }
  }

  merge(left, right, half_size, half_size);

  // groupt the two different arrays together
  for(i = 0; i < half_size; i++)
    ptr[i] = left[i];

  outer_counter = 0;
  for(i = half_size;i < size; i++)
  {
    ptr[i] = right[outer_counter];
    outer_counter++;
  }
  return ptr; 
}

void merge(int *left, int*right, int left_size, int right_size)
{
  if (left_size == 1 && right_size == 1)
  {
    // if the array has just one element
    if (left[0] != right[0])
    { // we may have to swap them
      int temp = right[0];
      right[0] = left[0];
      left[0] = temp;
    }
  }
  else 
  { 
    int i;
    int j = 0;
    for (i = 0; i < left_size; i++)
    {
      if (left[i] > right[j])
      {
        int temp = right[j];
        right[j] = left[i];
        left[i] = temp;
        j++;
      }
    }
    j = 0;
    for(i = 0; i < right_size; i++)
    {
      if (right[i]> left[i])
      {
        int temp = right[i];
        right[i] = left[j];
        left[j] = temp;
        j++;
      }
    }
  }

  return;
}