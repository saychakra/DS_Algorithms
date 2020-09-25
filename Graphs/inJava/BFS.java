import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    private int V; // no. of vertices
    private LinkedList<Integer> adj[]; // adjacency list representation

    // default constructor for creating the graph structure using an adjacency list representation
    BFS(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    // creating the edges of the graph
    // add v to u's list
    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    void BFSTraversal(int s) {
        // create an array of visited, which stores the whether a node is visited of not
        boolean[] visited = new boolean[V]; // although by default it is set to false in java
        // marks all the vertices as "not visited first"
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // creating a queue for the BFS traversal
       Queue<Integer> q = new LinkedList<>();

        // mark the current node as visited and enqueue it
        visited[s] = true;
        q.add(s);

        while (q.size() != 0) {
            s = q.poll();
            System.out.print(s + ", ");

            // get all the adjacent vertices of the dequeued vertex s
            // if that adjacent vertex has not been visited then mark it true and enqueue it
            Iterator<Integer> it = adj[s].listIterator(); // creating an iterator of integer type to traverse through that particular linked list
            while (it.hasNext()) {
                int printer = it.next();
                if (visited[printer] == false) {
                    visited[printer] = true;
                    q.add(printer);
                }
            }
        }
    }

    public static void main(String[] args) {
        int V = 4;
        BFS g= new BFS(V);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is the BFS traversal, starting from vertex 2 : ");
        g.BFSTraversal(2);
    }

}
