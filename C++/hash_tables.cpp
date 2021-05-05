#include <iostream>

using std::cout;

template <class dtype_val>
struct hash_value {
  char key[10];
  dtype_val val;
};

template<class val_type, int size>
class hash_table
{
  public:
    int max_key_size = 10;
    hash_value<val_type> data[size];

    // key maximum 10 chars
    int hashing(char *key)
    {
      int hash = 0;
      int i;

      // basic hashing algorithm founded at:
      // [link]
      for (i = 0; i < max_key_size; i++)
      {
        hash = hash + key[i] * i;
      }

      hash = hash % size;

      return hash;
    }

    void set(char *key, int value)
    {
      int index = hashing(key);
      for (int i = 0; i < max_key_size; i++)
      {
        data[index].key[i] = key[i];
      }
      data[index].val = value;
      return;
    }

  
};

int main()
{
  hash_table<int, 10> table;

  char k [10] = "gabriele";


  table.set(k, 10);

  cout << table.data[5].val;
  return 0;
}

/*
hash function
int hash (char key [10])
{

  for (i = 0; i < 10; i++)
  {
    hash = hash + key[i] * i;
  }

  hash = hash % 10;

  return hash;
} 
*/