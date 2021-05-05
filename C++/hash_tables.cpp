#include <iostream>

using std::cout;
using std::endl;
using std::cin;

// to create an hash table we have to first
// store somewhere the key and the value
template <class dtype_key, class dtype_val>
struct hash_obj {
  dtype_key key;
  dtype_val value;
};

template <class dtype_key, class dtype_value>
class hash_table 
{
  public:
    int data [10];

  void hashing (dtype_key key)
  {
    int i;
    int code = 0;
    for (i = 0; i < key[i]; i++)
    {
      cout << key[i];
      code = code + i + 1;
    }

    cout << code;
  }
};

int main() 
{
  hash_table<char[10], int> my_hash;
  char name [10] = {"qwerrt"};
  my_hash.hashing(name);

  return 0;
}