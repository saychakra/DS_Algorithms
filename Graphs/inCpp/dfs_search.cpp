#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+3;
vector<int>g[N];
bool visited[N];

//recursive solution to find whether there is a possible path from one node to another
void dfs(int u) {
    // mark that node as visited.
    // otherwise for undirected graphs such as this one there will be an infinite loop
    visited[u] = 1;
    
    // we will be iterating over the list of values in g[u] and check if those values are visited
    // if visited, then we will be ignoring it. 
    // otherwise, we need to dfs on it

    for(int v: g[u]) {
        if(visited[v] == true)  continue;
        else                    dfs(v);
    }

}

int main () {
    freopen("dfs_search_in.in", "r", stdin);
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    while(m--) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u); // for directed graphs, this should be removed   
    }

    //querying on / dfs searching on all the nodes which can be visited from node 1
    dfs(1);

    // checking if node 6 was visited. 
    // this should return true
    if(visited[6] == true)  cout << "6 was visited from 1" << endl;
    else                    cout << "6 could not be reached from 1" << endl;

    // checking if node 4 was visited. 
    // this should return false
    if(visited[4] == true)  cout << "4 was visited from 1" << endl;
    else                    cout << "4 could not be reached from 1" << endl;

    return 0;
}

/*

Our input graph structure

1 ---- 2 ---- 6           4 ---- 5
\     /
   3
These are undirected graphs

*/