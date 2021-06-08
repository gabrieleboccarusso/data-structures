#include <iostream>

using std::cout;
using std::cin;

int factorial(int number)
{
  if (number > 1)
    number = number * factorial(number - 1);
  else
    return number; 
}

int main()
{
  int n;
  cout << "enter the number: ";
  cin >> n;
  cout << "the factorial of " << n << " is: "<< factorial(n);

  return 0;
}