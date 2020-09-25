#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int src, int dest) {
    adjList[src].push_back(dest);
    adjList[dest].push_back(src); // since this is an undirected graph, we need to put in both the directions
}

void printGraph(vector<int> adjList[], int v) {
    for(int i = 0; i < v; i++) {
        cout << "Adjacency list of vertex " << i << "\nhead ";
        for(auto x : adjList[i]) {
            cout << " -> " << x;
        }
        cout << endl;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int v;
    cout << "Enter the number of vertices you wish to enter: ";
    cin >> v;
    vector<int> adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 4);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 4);

    cout << "\nPrinting the graph in adjacency list format: ";
    printGraph(adjList, v);
    return 0;
}

/*
0  -  1 \
|  /  | / 2
4 -   3
*/