#include <iostream>

using std::cout;

template <class dtype, int max>
class static_array
{
  public:
    int length = 0;
    dtype data[max];
};

int main()
{
  static_array<int, 5> arr;

  cout << arr.length;
  return 0;
}