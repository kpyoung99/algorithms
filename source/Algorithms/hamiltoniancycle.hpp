#include "../Graphs/Graph.hpp"

#define UNVISITED 0
#define VISITED 1

/** hamiltonain_cycle(Graph& G, unsigned int v, unsigned int path_len)
 * Recursively searches for a Hamiltonain cycle in G, returning true if one is
 * found and false otherwise.
 * Each call assumes that path_len number of edges have been found so far, and
 * attempts to add an unvisited vertex to the cycle.
 * A cycle is successfully found when the last unvisited node has been visited
 * (i.e. when path_len is one less than the number of nodes) and an edge is
 * found from the final node to the start node.
 * You may use VISITED and UNVISITED to mark nodes as one or the other.
 *      e.g. G.set_node(0, VISITED);
 */
bool hamiltonian_cycle(Graph& G, unsigned int v, unsigned int path_len) {
  if (path_len == G.node_count() - 1) {
    std::vector<int> neighbors = G.neighbors(v);
    for (int neighbor : neighbors) {
      if (neighbor == 0) {
        return true;
      }
    }
    return false;
  }
  G.set_value(v, VISITED);
  std::vector<int> neighbors = G.neighbors(v);
  for (int neighbor : neighbors) {
    if (G.get_value(neighbor) == UNVISITED) {
      if (hamiltonian_cycle(G, neighbor, ++path_len))
        return true;
      --path_len;
      G.set_value(neighbor, UNVISITED);
    }
  }
  return false;
}

/** hamiltonian_cycle(Graph& G)
 * Decides whether there exists a hamiltonian cycle in G by making a call to the
 * recursive function by the same name.
 */
bool hamiltonian_cycle(Graph& G) {
  return hamiltonian_cycle(G, 0, 0);
}
