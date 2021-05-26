#include <iostream>

using std::cout;

void selection_sort(int arr[], int size);
void swap(int *n1, int *n2);

int main()
{
  int arr[] = {9, 5, 9, 3, 78, 25, 12};

  selection_sort(arr, 7);

  return 0;
}

void selection_sort(int arr[], int size)
{
  int i, j;

  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      if (arr[i] < arr[j])
        swap(&arr[i], &arr[j]); // O(n^2)

  for(i = 0; i < size; i++)
    cout << arr[i] << " ";

  return;
}

void swap(int *n1, int *n2)
{
  int temp = *n2;
  *n2 = *n1;
  *n1 = temp;
}