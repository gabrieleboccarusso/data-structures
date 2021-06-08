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

    for (i = 0; i < num_nodes+1; i++)
    {
      cout << i << " --> ";
      for (j = 0; j < num_nodes+1; j++)
      {
        //cout << adjacent_list[i][j];
        // cout << " ";
        if (adjacent_list[i][j] == 1)
        {
          cout << j << " ";
        }
      }
      cout << endl;
    }

    return;
  }

  void addEdge(int first_node, int second_node)
  {
    adjacent_list[first_node][second_node] = 1;
    adjacent_list[second_node][first_node] = 1;

    return;
  }

  void addNode()
  {
    num_nodes++;

    return;
  }
};

int main()
{
  Graph<10> my_graph;
  my_graph.addNode(); 
  my_graph.addNode();
  my_graph.addNode();
  my_graph.addNode();
  my_graph.addNode();
  my_graph.addNode();

  my_graph.addEdge(3, 1);
  my_graph.addEdge(3, 4);
  my_graph.addEdge(4, 2);
  my_graph.addEdge(4, 5);
  my_graph.addEdge(1, 2);
  my_graph.addEdge(1, 0);
  my_graph.addEdge(0, 2);
  my_graph.addEdge(6, 5);
  my_graph.showConnections();
  return 0;
}