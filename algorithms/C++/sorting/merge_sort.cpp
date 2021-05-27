#include <iostream>

using std::cout;
using std::endl;

void merge_sort(int arr[], int size);

int main()
{
  int size = 4;
  int arr[] = {3, 4, 1, 2};
  int *ptr = arr;

  merge_sort(arr, size);

  return 0;
}

// in those first cases we'll not take in consideration
// that size may be a non-pair number
void merge_sort(int *ptr, int size)
{
  int i;
  // if size is 2
  if (size == 2)
  {
    // output the array
    for(i = 0; i < size; i++)
      cout << ptr[i] << " ";

    cout << endl;
  }
  // else if size is greater than two
  else if (size > 2)
  { // create two array with half the size
    int half_size = size/2;
    int *left = new int[half_size];
    int *right = new int [half_size];

    // fill the two arrays
    for (i = 0; i < half_size; i++)
      left[i] = ptr[i];

    int outer_counter = 0;
    for (i = half_size; i < size; i++)
    {  
      right[outer_counter] = ptr[i];
      outer_counter++;
    }
    // call again the function (recurison)
    merge_sort(left, half_size);
    merge_sort(right, half_size);
  }
}