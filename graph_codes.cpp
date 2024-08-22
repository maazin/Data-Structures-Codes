
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <queue>

// using namespace std;

// void bfs(unordered_map<int, vector<int>>& graph, int startVertex) {
//     unordered_set<int> visited;
//     queue<int> q;

//     visited.insert(startVertex);
//     q.push(startVertex);

//     while (!q.empty()) {
//         int currentVertex = q.front();
//         q.pop();
//         cout << "Visited vertex: " << currentVertex << endl;

//         for (int neighbor : graph[currentVertex]) {
//             if (visited.count(neighbor) == 0) {
//                 visited.insert(neighbor);
//                 q.push(neighbor);
//             }
//         }
//     }
// }

// int main() {
//     unordered_map<int, vector<int>> graph;

//     // Example graph
//     graph[0] = {1, 2};
//     graph[1] = {0, 3, 4};
//     graph[2] = {0, 4};
//     graph[3] = {1, 4};
//     graph[4] = {1, 2, 3};

//     int startVertex = 0;
//     bfs(graph, startVertex);

//     return 0;
// }

// g++ -o trav -std=c++11  traversal.cpp
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// void dfs(unordered_map<int, vector<int>>& graph, int startVertex, unordered_set<int>& visited) {
//     visited.insert(startVertex);
//     cout << "Visited vertex: " << startVertex << endl;

//     for (int neighbor : graph[startVertex]) {
//         if (visited.count(neighbor) == 0) {
//             dfs(graph, neighbor, visited);
//         }
//     }
// }

// int main() {
//     unordered_map<int, vector<int>> graph;

//     // Example graph
//     graph[0] = {1, 2};
//     graph[1] = {0, 3, 4};
//     graph[2] = {0, 4};
//     graph[3] = {1, 4};
//     graph[4] = {1, 2, 3};

//     unordered_set<int> visited;
//     int startVertex = 0;
//     dfs(graph, startVertex, visited);

//     return 0;
// }
//----

// counting components - BFS
// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// // Adjacency list representation of the graph
// vector<vector<int>> graph;
// // Keeps track of the visited status of each vertex
// vector<bool> visited;

// // Function to count the number of connected components in the graph
// int countComponents() {
//     int components = 0; // Initialize the number of connected components to 0
//     queue<int> q; // Create a queue to perform BFS

//     // Iterate through all the vertices in the graph
//     for (int i = 0; i < graph.size(); i++) {
//         // If a vertex is not visited yet
//         if (!visited[i]) {
//             components++; // Increment the number of connected components
//             visited[i] = true; // Mark the vertex as visited
//             q.push(i); // Enqueue the vertex

//             // Perform BFS starting from the current vertex
//             while (!q.empty()) {
//                 int v = q.front(); // Dequeue a vertex from the queue
//                 q.pop();

//                 // Mark the dequeued vertex as explored
//                 for (int neighbor : graph[v]) {
//                     if (!visited[neighbor]) {
//                         visited[neighbor] = true; // Mark the neighbor as visited
//                         q.push(neighbor); // Enqueue the neighbor
//                     }
//                 }
//             }
//         }
//     }

//     return components; // Return the total number of connected components
// }

// int main() {
//     // Example graph
//     graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}, {5}};
//     visited.resize(graph.size(), false); // Initialize the visited vector

//     int numComponents = countComponents(); // Call the countComponents function
//     cout << "Number of connected components: " << numComponents << endl;

//     return 0;
// }



/*
#include <iostream>
#include <vector>

using namespace std;

// Adjacency list representation of the graph
vector<vector<int>> graph;
// Keeps track of the visited status of each vertex
vector<bool> visited;

// Function to perform DFS recursively
void dfsRecursive(int v) {
    // Mark the current vertex as discovered
    visited[v] = true;

    // Recursively visit all the undiscovered neighbors
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor);
        }
    }

    // Mark the current vertex as explored
    visited[v] = true;
}

// Function to count the number of connected components in the graph
int countComponents() {
    int components = 0; // Initialize the number of connected components to 0

    // Iterate through all the vertices in the graph
    for (int i = 0; i < graph.size(); i++) {
        // If a vertex is not visited yet
        if (!visited[i]) {
            components++; // Increment the number of connected components
            dfsRecursive(i); // Perform DFS starting from the current vertex
        }
    }

    return components; // Return the total number of connected components
}

int main() {
    // Example graph
    graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    visited.resize(graph.size(), false); // Initialize the visited vector

    int numComponents = countComponents(); // Call the countComponents function
    cout << "Number of connected components: " << numComponents << endl;

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Adjacency list representation of the graph
vector<vector<int>> graph;
// Keeps track of the distance of each vertex from the starting vertex
unordered_map<int, int> distances;


// Function to calculate the distance between two vertices using BFS
int distance(int start, int end) {
    // Initialize the distance and parent maps
    for (int i = 0; i < graph.size(); i++) {
        distances[i] = -1;
       
    }

    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // Enqueue the neighbors of the current vertex
        for (int neighbor : graph[v]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[v] + 1;
               
                q.push(neighbor);

                // If the current neighbor is the target vertex, return the distance
                if (neighbor == end) {
                    return distances[neighbor];
                }
            }
        }
    }

    // If the target vertex is not reachable, return -1
    return -1;
}



int main() {
    // Example graph
    graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};

    int start = 0, end = 3;
    int dist = distance(start, end);
    cout << "Distance between " << start << " and " << end << ": " << dist << endl;

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// // Adjacency list representation of the graph
// vector<vector<int>> graph;
// // Keeps track of the visited status of each vertex
// vector<bool> visited;
// // Stores the topological ordering of the vertices
// vector<int> topologicalOrder;

// // Function to perform DFS recursively
// void dfsRecursive(int v) {
//     // Mark the current vertex as discovered
//     visited[v] = true;
    
//     // Recursively visit all the undiscovered neighbors
//     for (int neighbor : graph[v]) {
        
       
//         if (!visited[neighbor]) {
//             dfsRecursive(neighbor);
//         }
       
//     }

//     // Add the current vertex to the topological ordering
//     topologicalOrder.push_back(v);
//     // cout<<v<<endl;
// }

// // Function to perform topological sorting
// vector<int> topologicalSort() {
//     // Initialize the visited vector
//     visited.resize(6, false);

//     // Perform DFS on all the unvisited vertices
//     for (int i = 0; i < 6; i++) {
//         if (!visited[i]) {
//             dfsRecursive(i);
//         }
//     }

//     // Reverse the topological ordering and return it
//     reverse(topologicalOrder.begin(), topologicalOrder.end());
//     return topologicalOrder;
// }

// int main() {
//     // Example graph
//     graph = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}, {0, 1}};

//     vector<int> result = topologicalSort();

//     cout << "Topological Ordering: ";
//     for (int vertex : result) {
//         cout << vertex << " ";
//     }
//     cout << endl;

//     return 0;
// }



// using namespace std;

// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };



// Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
//     if (visited.count(node))
//         return visited[node];

//     Node* clone = new Node(node->val);
//     visited[node] = clone;

//     for (Node* neighbor : node->neighbors) {
//         clone->neighbors.push_back(dfs(neighbor, visited));
//     }

//     return clone;
// }
// Node* cloneGraph(Node* node) {
//     if (node == nullptr)
//         return nullptr;

//     unordered_map<Node*, Node*> visited;
//     return dfs(node, visited);
// }

// int main() {
//     // Create a sample graph
//     Node* node1 = new Node(1);
//     Node* node2 = new Node(2);
//     Node* node3 = new Node(3);
//     Node* node4 = new Node(4);

//     node1->neighbors = {node2, node4};
//     node2->neighbors = {node1, node3};
//     node3->neighbors = {node2, node4};
//     node4->neighbors = {node1, node3};

//     // Clone the graph
//     Node* clonedGraph = cloneGraph(node1);

//     // Print the cloned graph
//     unordered_map<Node*, bool> visited;
//     queue<Node*> q;
//     q.push(clonedGraph);
//     visited[clonedGraph] = true;

//     while (!q.empty()) {
//         Node* curr = q.front();
//         q.pop();
//         cout << "Node " << curr->val << ": ";
//         for (Node* neighbor : curr->neighbors) {
//             cout << neighbor->val << " ";
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 q.push(neighbor);
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }

/*
Clone a given graph
Explanation:

We define a Node class to represent the nodes in the graph, with a value and a list of neighboring nodes.
The cloneGraph() function takes a reference to the starting node of the graph and returns a reference to the cloned graph.
Inside the cloneGraph() function, we first check if the starting node is nullptr, in which case we return nullptr.
We then use a recursive helper function dfs() to perform the depth-first search and clone the graph.
In the dfs() function, we first check if the current node has already been visited. If so, we return the corresponding cloned node from the visited map.
If the node hasn't been visited yet, we create a new cloned node with the same value, and store it in the visited map.
We then recursively call the dfs() function for each neighbor of the current node, and add the cloned neighbors to the cloned node's neighbors list.
Finally, we return the cloned node.
In the main() function, we create a sample graph, call the cloneGraph() function to clone the graph, and then print the cloned graph using a breadth-first search traversal.
*/

// g++ -o trav -std=c++11 traversal.cpp






bool dfs(int node, vector<vector<int>>& graph, vector<int>& state) {
    if (state[node] == 1) // Cycle detected
        return false;

    if (state[node] == 2) // Already visited
        return true;

    state[node] = 1; // Mark as visiting

    for (int neighbor : graph[node]) {
        if (!dfs(neighbor, graph, state))
            return false;
    }

    state[node] = 2; // Mark as visited
    return true;
}
bool canFinishCourses(int numCourses, vector<vector<int>>& prerequisites) {
    // Create the adjacency list
    vector<vector<int>> graph(numCourses);
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
    }

    // Keep track of the state of each node
    vector<int> state(numCourses, 0); // 0 - unvisited, 1 - visiting, 2 - visited

    // Perform DFS
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, graph, state))
            return false;
    }

    return true;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    bool result = canFinishCourses(numCourses, prerequisites);
    cout << "Can all courses be finished? " << (result ? "Yes" : "No") << endl;

    return 0;
}


/*
Explanation:
 Course Schedule problem-
We first create the adjacency list graph to represent the course prerequisites.
We then use a state vector to keep track of the state of each node during the DFS traversal:
0 - unvisited
1 - visiting (part of the current DFS path)
2 - visited
In the canFinishCourses() function, we iterate through all the courses and call the dfs() function on each course.
The dfs() function performs the depth-first search starting from the given node:
If the current node is marked as visiting (state[node] == 1), it means a cycle has been detected, and we return false.
If the current node is marked as visited (state[node] == 2), it means we have already processed this node, and we can safely return true.
Otherwise, we mark the current node as visiting (state[node] = 1) and recursively call dfs() on all its neighbors.
If any of the recursive calls return false, we return false from the current call.
If all the recursive calls return true, we mark the current node as visited (state[node] = 2) and return true.
If the dfs() function returns true for all courses, it means all the courses can be finished, and we return true from the canFinishCourses() function. Otherwise, we return false.
In the main() function, we provide an example input and call the canFinishCourses() function to get the result.

*/