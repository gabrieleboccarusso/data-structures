#include <iostream>

using std::cout;

class hash_table
{

}

int main()
{
  char key[10] = "giovanni";
  cout << hash(key);

  return 0;
}

/*
hash function
int hash (char key [10])
{
  int hash = 0;
  int i;

  for (i = 0; i < 10; i++)
  {
    hash = hash + key[i] * i;
  }

  hash = hash % 10;

  return hash;
} 
*/