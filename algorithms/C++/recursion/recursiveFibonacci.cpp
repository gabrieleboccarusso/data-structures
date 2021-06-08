#include <iostream>

using std::cout;

int iterative_f(int n)
{
  int n1 = 0;
  int n2 = 1;
  int n3;
  for (int i = 1; i < n; i++)
  {
    n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
  }

  return n3;
}

int recursive_f(int n)
{
  if (n > 2)
    n = recursive_f(n - 1) + recursive_f(n - 2);
  else
    return n;
}

int main()
{
  cout << iterative_f(7);

  return 0;
}