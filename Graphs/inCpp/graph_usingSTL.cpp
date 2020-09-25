#include <bits/stdc++.h>
using namespace std;

// function to add an edge to undirected graph
void addEdge(vector<int> adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// the DFSUtil function
// void DFSUtil(int currNode, vector<int> adj[], vector<bool> &visited) {
//     // marking the current node as visited and printing it
//     visited[currNode] = true;
//     cout << currNode << ", ";

//     // recurring over all the adjacent nodes of the current node
//     for (int i = 0; i < adj[currNode].size(); i++)
//         if (visited[adj[currNode][i]] == false)
//             DFSUtil(adj[currNode][i], adj, visited);
// }

// the main dfs function:
void DFS(vector<int> adj, int V) {
    // creating a boolean vector of visited to store the visited vertices
    vector<bool> visited(V, false); // inititalizing all the elements to false in the beginning
    for(int i = 0; i < V; i++) {
        if (visited[i] == false) {
            //DFSUtil(i, adj, visited);
            cout << "Yo\n";
        }
    }
}

int main() {
    int V = 5; // specifying the number of vertices on the graph
    vector<int> adj[V]; // creating an array of vectors for specifying the number of adjacent vertices of each vertex

    // adding vertices:
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    cout << "\nPrinting the DFS traversal of the graph: ";
    DFS(adj, V);
    return 0;
}