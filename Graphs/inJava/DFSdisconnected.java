import java.util.Iterator;
import java.util.LinkedList;

public class DFSdisconnected {
    private int V;
    private LinkedList<Integer> adj[];

    // creating the graph structure
    DFSdisconnected(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    // adding edges v to the list of u
    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    // the recursive util function for creating and recursively handling the dfs traversal
    // for each and every non connected nodes within the graph.
    void DFSUtil(int currNode, boolean[] visited) {
        visited[currNode] = true;
        System.out.print(currNode + ", ");

        Iterator<Integer> it = adj[currNode].listIterator();
        while (it.hasNext()) {
            int n = it.next();
            if (visited[n] == false) {
                DFSUtil(n, visited);
            }
        }
    }

    void DFSdisconPrinter() {
        boolean[] visited = new boolean[V]; // by default all the values are set to false in java
        // the recursive function is called again and again for all the nodes in general
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
               DFSUtil(i, visited);
            }
        }
    }
    public static void main(String[] args) {
        DFSdisconnected g = new DFSdisconnected(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is Depth First Traversal");

        g.DFSdisconPrinter();
    }
}
