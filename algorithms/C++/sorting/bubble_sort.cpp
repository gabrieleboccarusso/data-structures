#include <iostream>

using std::cout;

void bubble(int arr[], int size);

int main()
{

  int arr[] = {3, 2, 1};

  bubble(arr, 3);

  return 0;
}


void bubble(int arr[], int size)
{
  int i;
  int swap;

  for (i = 0; i < size; i++)
  {
    if (arr[i+1]) 
    {
      if (arr[i] > arr[i+1]) 
      {
        swap = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = swap;
      }
    }
  }

  for(i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }

  return;
}
