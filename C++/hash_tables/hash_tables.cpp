#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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

    val_type get(char *key)
    {
      int index = hashing(key);
      return data[index].val;
    }

};

int main()
{
  hash_table<int, 10> table;
  char key [10]; // used to get or set an item;
  int value; // value to set
  char choice = 'y'; // used to choose what to do
  while (choice != 'n')
  {
    cout << "enter 1 to put something in the associative array" << endl;
    cout << "enter 2 to get a value from the array" << endl;
    cout << "enter \"n\" to exit the program" << endl;
    cin >> choice;

    switch (choice)
    {
      case '1':
        cout << "enter key to set: ";
        cin >> key;
        cout << "enter the value: ";
        cin >> value;
        table.set(key, value);
        break;
      case '2':
        cout << "enter key to search: ";
        cin >> key;
        cout << table.get(key);
        break;
      case 'n':
        cout << "goodbye";
        break;
      default:
      cout << "I don't get it" << endl;
    }

  }
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