#include <bits/stdc++.h>
using namespace std;

class Graph {
    // by default all the unmentioned parameters are private
    int V; // specifies the number of vertices in the graph
    
    // pointer to an array containing adjacency list
    list <int> *adj;

    // a recursive function which is utilized by the dfs function
    void DFSUtil(int currNode, bool visited[]);

    public:
        Graph (int V); // default constructor to assign value to V

        //function to add edges to the graph
        void addEdge(int u, int v);

        // function for the dfs traversal
        void dfs(int startingNode);
};

Graph::Graph(int V) {
    this->V = V;
    // creating an array for each adjacent nodes in the graph
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v); // add v to u's list
}

void Graph::DFSUtil(int currNode, bool visited[]) {
    // mark the current node as visited and print it
    visited[currNode] = true;
    cout << currNode << ", ";

    // recur for all the adjacent vertices of the current vertex
    list <int>::iterator it;
    for(it = adj[currNode].begin(); it != adj[currNode].end(); it++) {
        if (visited[*it] == false) 
            DFSUtil(*it, visited);
    }
}

// dfs traversal function of graph, starting from the starting node as mentioned
void Graph::dfs(int startingNode) {
    bool *visited = new bool[V];
    // firstly mark all the veritces as not visited
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // call the recursive util function from the starting node
    DFSUtil(startingNode, visited);
} 

int main() {

    Graph g(4);
    // adding the edges to the graoh
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // printing the dfs traversal of the graph
    cout<< "\n Printing the DFS traversal of the graph starting from the node 2: \t";
    g.dfs(2);
    return 0;
}