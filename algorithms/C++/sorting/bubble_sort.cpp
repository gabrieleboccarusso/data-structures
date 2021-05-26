#include <iostream>

using std::cout;

void bubble(int arr[], int size);
void swap(int *n1, int *n2);

int main()
{

  int arr[] = {8, 3, 2, 1, 2 ,9 , 4, 0};

  bubble(arr, 8);

  return 0;
}


void bubble(int arr[], int size)
{
  int i;
  bool swapped = true;

  //for (i = 1; i < size ; i++)
  while (swapped)
  {
      swapped = false;
      for (i = 1; i < size; i++)
      {
        if (arr[i - 1] > arr[i]) 
        {
          swap(&arr[i-1], &arr[i]);
          swapped = true;
        }
      }
  }

  for(i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }

  return;
}

void swap(int *n1, int *n2)
{
  int swap = *n1;
  *n1 = *n2;
  *n2 = swap;

  return;
}
