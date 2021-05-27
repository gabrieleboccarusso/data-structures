#include <iostream>

using std::cout;
using std::endl;

void selection_sort(int arr[], int size);

int main()
{
  int arr[] = {1, 8, 3, 2};
  int arr2[] = {8,3,2,1, 4};
  int size = 5;

  selection_sort(arr2, size);

  for(int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }

  return 0;
}

void selection_sort(int arr[], int size)
{
  int i, j;
  int temp;

  for(i = 1; i < size; i++)
  {
    temp = arr[i];
    j = i-1;
    while(j >= 0 && arr[j] > temp)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }

  return;
}