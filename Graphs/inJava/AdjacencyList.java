import java.util.LinkedList;
import java.util.Scanner;

public class AdjacencyList {
    static class Graph {
        int V;
        LinkedList<Integer> adjListArray[];

        Graph(int V) {
            this.V = V;

            // the size of the array is the number of vertices specified
            adjListArray = new LinkedList[V];

            // now a new list needs to be created for every vertex
            for (int i = 0; i < V; i++) {
                adjListArray[i] = new LinkedList<>();
            }
        }
    }

    static void addEdge(Graph G, int src, int dest) {
        // adding an edge from source to destination
        G.adjListArray[src].addFirst(dest);

        // since the graph is undirected, an edge is also added from destination to source
        G.adjListArray[dest].addFirst(src);
    }

    //utility function to print the graph
    static void printGraph(Graph G) {
        for (int i = 0; i < G.V; i++) {
            System.out.println("Adjacency list of vertex " + i);
            System.out.print("head");
            for(Integer pCrawl: G.adjListArray[i]){
                System.out.print(" -> "+pCrawl);
            }
            System.out.println("\n");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices you wish to enter: ");
        int n = sc.nextInt();
        Graph graph = new Graph(n);
        addEdge(graph, 0, 1);
        addEdge(graph, 0, 4);
        addEdge(graph, 1, 2);
        addEdge(graph, 1, 3);
        addEdge(graph, 1, 4);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        System.out.println("Printing the graph in adjacency list format:");
        printGraph(graph);
    }
}

/*
0  -  1 \
|  /  | / 2
4 -   3
*/