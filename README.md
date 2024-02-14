# Dijkstra-Algorithm

    A---(2)---B---(5)---C
    |        / \        |
  (3)      (6) (4)     (1)
    |      /     \      |
    D----(7)----E----(8)-F


You have a graph representing a road network between cities, and you want to find the shortest path from a starting city to a destination city.

In this graph:

Cities are represented by nodes (A, B, C, D, E, F).
Roads are represented by edges between nodes, with the numbers in parentheses indicating the distance (weight) of each edge.
Let's say you want to find the shortest path from city A to city F using Dijkstra's algorithm.

Initialization: Start with an empty set of visited nodes and set the distance to each node to infinity, except for the starting node (A), which is set to 0.

Choose the unvisited node with the smallest known distance: In this case, the starting node is A with a distance of 0.

Update distances: Update the distances to neighboring nodes by adding the weight of the edge connecting them to the current node. If this new distance is shorter than the previously known distance to that node, update it.

Repeat steps 2 and 3 until all nodes are visited: Continue selecting the unvisited node with the smallest known distance and updating distances until the destination node (F) is visited.

Backtrack to find the shortest path: Once the destination node is reached, backtrack from the destination node to the starting node by following the predecessors recorded during the algorithm's execution. This will give you the shortest path from A to F.

Using Dijkstra's algorithm, you can find the shortest path from city A to city F, considering the weights of the edges in the graph.

