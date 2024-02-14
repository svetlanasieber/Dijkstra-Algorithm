#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a node (city) in the graph
struct Node {
    char id; // City ID
    int distance; // Distance from the source node
    Node(char _id, int _distance) : id(_id), distance(_distance) {}
};

// Structure to represent an edge (road) in the graph
struct Edge {
    char from; // Source city ID
    char to; // Destination city ID
    int weight; // Distance between cities
    Edge(char _from, char _to, int _weight) : from(_from), to(_to), weight(_weight) {}
};

// Comparator function for priority queue (min heap)
struct CompareDistance {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance; // Compare distances (for min heap)
    }
};

// Dijkstra's algorithm to find the shortest path in a graph
vector<int> dijkstra(vector<vector<Edge>>& graph, char source, char destination) {
    vector<int> distances(256, numeric_limits<int>::max()); // Initialize distances to infinity
    vector<int> predecessors(256, -1); // Store predecessors for backtracking
    priority_queue<Node, vector<Node>, CompareDistance> pq; // Priority queue for selecting the next node

    distances[source] = 0; // Distance from source to source is 0
    pq.push(Node(source, 0)); // Add source node to the priority queue

    while (!pq.empty()) {
        Node currentNode = pq.top(); // Get the node with the smallest distance
        pq.pop();

        char currentCity = currentNode.id;
        int currentDistance = currentNode.distance;

        if (currentCity == destination) {
            break; // Found shortest path to destination
        }

        for (const Edge& edge : graph[currentCity]) {
            char neighborCity = edge.to;
            int newDistance = currentDistance + edge.weight;

            if (newDistance < distances[neighborCity]) {
                distances[neighborCity] = newDistance; // Update distance to neighbor
                predecessors[neighborCity] = currentCity; // Record predecessor for backtracking
                pq.push(Node(neighborCity, newDistance)); // Add neighbor to priority queue
            }
        }
    }

    // Backtrack from destination to source to find the shortest path
    vector<int> shortestPath;
    char currentCity = destination;
    while (currentCity != source) {
        shortestPath.push_back(currentCity);
        currentCity = predecessors[currentCity];
    }
    shortestPath.push_back(source); // Add source city to the shortest path
    reverse(shortestPath.begin(), shortestPath.end()); // Reverse the path to get it in correct order

    return shortestPath;
}

int main() {
    // Define the graph (road network)
    vector<vector<Edge>> graph(256); // Using ASCII values for city IDs

    // Add edges (roads) to the graph
    graph['A'].push_back(Edge('A', 'B', 2));
    graph['A'].push_back(Edge('A', 'D', 3));
    graph['B'].push_back(Edge('B', 'A', 2));
    graph['B'].push_back(Edge('B', 'C', 5));
    graph['B'].push_back(Edge('B', 'D', 6));
    graph['B'].push_back(Edge('B', 'E', 4));
    graph['C'].push_back(Edge('C', 'B', 5));
    graph['C'].push_back(Edge('C', 'F', 1));
    graph['D'].push_back(Edge('D', 'A', 3));
    graph['D'].push_back(Edge('D', 'B', 6));
    graph['D'].push_back(Edge('D', 'E', 7));
    graph['E'].push_back(Edge('E', 'B', 4));
    graph['E'].push_back(Edge('E', 'D', 7));
    graph['E'].push_back(Edge('E', 'F', 8));
    graph['F'].push_back(Edge('F', 'C', 1));
    graph['F'].push_back(Edge('F', 'E', 8));

    // Find the shortest path from city A to city F
    char source = 'A';
    char destination = 'F';
    vector<int> shortestPath = dijkstra(graph, source, destination);

    // Output the shortest path
    cout << "Shortest path from city " << source << " to city " << destination << ": ";
    for (char city : shortestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
