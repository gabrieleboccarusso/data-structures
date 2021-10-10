#include <iostream>

using std::cout;
using std::endl;

template <class T>
class Rectangle 
{
  public:
    int width;
    int height;
    T data[max];
  // constructor
  Rectangle (int set_width, int set_height, int set_data)
  {
    width = set_width;
    height = set_height;
    data[set_data];
    data[0] = 1;
  }

    int area ()
    {
      return width * height;
    }
};

int main() 
{
  Rectangle<int> my_rect (5, 10, 1);

  cout << "area: " << my_rect.area();
  cout << endl;
  cout << my_rect.data;
  return 0;
}