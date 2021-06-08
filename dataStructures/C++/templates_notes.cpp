#include <iostream>

template <class generic>
generic sum (generic a, generic b)
{
  return a + b;
}

template <class first_type, class second_type>
bool are_equal (first_type a, second_type b)
{
  bool answer = false;

  if (a == b)
  {
    answer = true;
  }

  return answer;
}

// template aren' just for generic types
template <class generic_num, int m>
generic_num multiply (generic_num number)
{
  return number * m;
}

int main() 
{
  std::cout << "using templates\n";
  int first_number = 5;
  int second_number = 10;

  // using the function created with the template
  int x = sum<int>(first_number, second_number);
  std::cout << x;
  std::cout << std::endl << sum<int> (2,3);

  int var = 1;
  char var2 = 'a';

  std::cout << "\nare this two types equal?";

  if (are_equal(var, var2))
  {
    std::cout << "they are equal\n";
  }
  else {
    std::cout << "\nthey are not\n";
  }

  std::cout << multiply<float, 2> (4.5);

  return 0; 
}