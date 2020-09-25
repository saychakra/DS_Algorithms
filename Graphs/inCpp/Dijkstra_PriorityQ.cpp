#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void shortestPath(vector<iPair> adj[], int V, int src) {
    // create a priority queue based on min heap to store the vertices that have been preprocessed
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // create a vector for distances and initialize all the values to infinity
    vector<int> dist(V, numeric_limits<int>::max());
        
    // enqueue the source node itself and set its distance to 0
    pq.push(make_pair(0, src));
    dist[src] = 0;

    //loop till the priority queue is not empty or all the distances are not finalized
    while(pq.empty() == false) {
        int curr = pq.top().second;
        pq.pop();

        //get all the adjacent vertices of the current vertex;
        for(auto it : adj[curr]) {
            // get the vertex label and weight of the adjacent vertices of the current vertex
            int adjV = it.first;
            int weight = it.second;

            // if there is a shorter path from the source to this vertex then update the value
            if ((dist[curr] + weight) < dist[adjV]) {
                dist[adjV] = (dist[curr] + weight);
                // push the updated value in the min heap
                pq.push(make_pair(dist[adjV], adjV));
            }
        }
    }
    
    // print the shortest distances stored in the dist vector
    printf("Vertex | Distance from Source\n");
    for(int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// function to add edges in the form of a adjacency list
void addEdge(vector<iPair> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

int main() {

    int V = 9; // there are 9 vertices in total
    vector<iPair> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortestPath(adj, V, 0);
    return 0;
}