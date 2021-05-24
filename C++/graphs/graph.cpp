#include <iostream>

using std::cout;
using std::endl;

template <int size>
class Graph {
  private:
  int num_nodes;
  int adjacent_list [size][size];
  public:
  Graph ()
  {
    num_nodes = 0;

    int i, j;

    for (i = 0; i < size; i++)
      for (j = 0; j < size; j++)
        adjacent_list[i][j] = 0;
  }

  void showConnections()
  {
    int i, j;

    for (i = 0; i < size; i++)
    {
      cout << i << ": ";
      for (j = 0; j < size; j++)
      {
        cout << adjacent_list[i][j];
        cout << " ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph<4> my_graph;
  my_graph.showConnections();
  return 0;
}