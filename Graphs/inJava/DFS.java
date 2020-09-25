import java.util.Iterator;
import java.util.LinkedList;

// the generic application of a DFS is done using a stack. Now here, we are using a linked list, in the form of a stack.

public class DFS {
    private int V;
    private LinkedList<Integer> adj[];

    //constructor for creating the graph structure
    DFS(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    // function to add edge v on the list of u
    void addEdge(int u, int v) {
        adj[u].add(v);
    }

    // recursive DFSUtil function for traversing the graph iteratively
    void DFSUtil(int currNode, boolean[] visited) {
        // mark the current node as visited and print it
        visited[currNode] = true;
        System.out.print(currNode + ", ");

        // recur for all the adjacent vertices of the current node
        Iterator<Integer> it = adj[currNode].listIterator();
        while (it.hasNext()) {
            int adjNode = it.next();
            if (visited[adjNode] == false)
                DFSUtil(adjNode, visited);
        }
    }

    void DFSPrinter(int startingNode) {
        // creating a boolean array to denote the array of visited nodes
        boolean[] visited = new boolean[V]; // by default all the values are marked false in java
        DFSUtil(startingNode, visited);

    }

    public static void main(String[] args) {
        DFS g = new DFS(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("Following is Depth First Traversal "+
                "(starting from vertex 2)");

        g.DFSPrinter(2);
    }
}
