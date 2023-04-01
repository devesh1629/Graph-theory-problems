// remove minimum number of edges to disconnect 2 vertices.
// http://myitlearnings.com/from-a-given-graph-delete-minimum-number-of-edges-such-that-there-is-no-path-from-start-node-to-end-node/

import java.util.*;

public class five {
    public static void main(String[] args) {
        String[] edges= new String[] { "1#2", "2#5", "2#4", "5#3", "5#4" };
        System.out.println(minEdgesToDel(edges));
    }

    public static int minEdgesToDel(String[] input1) {
        // create graph
        int n = input1.length;

        Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();

        int start = Integer.MAX_VALUE;
        int end = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            String[] sp = input1[i].split("#");
            int n1, n2;
            n1 = Integer.parseInt(sp[0]);
            n2 = Integer.parseInt(sp[1]);
            // Set the minimum vertex as start
            start = Math.min(start, Math.min(n1, n2));
            // Set the maximum vertex as max
            end = Math.max(end, Math.max(n1, n2));
            List<Integer> li;
            if (graph.containsKey(n1)) {
                li = graph.get(n1);
            } else {
                li = new ArrayList<Integer>();
            }
            li.add(n2);
            graph.put(n1, li);

            if (graph.containsKey(n2)) {
                li = graph.get(n2);
            } else {
                li = new ArrayList<Integer>();
            }
            li.add(n1);
            graph.put(n2, li);
        }

        int minEdgeDeleteCOunt = 0;
        while (true) {
            // ParentMap containing all parents of all the nodes in the BFS traversal path.
            Map<Integer, Integer> parentMap = bfs(graph, start);

            // If end is present on the path from start, then we need to delete all the edges from start to end
            if (parentMap.containsKey(end)) {
                minEdgeDeleteCOunt++;
                int parent = parentMap.get(end);
                int currEnd = end;
                // delete all edges in the current paths
                while (parent != -1) {
                    // As the graph is undirected, delete edge entry from both the nodes
                    deleteEdge(graph, parent, currEnd);
                    deleteEdge(graph, currEnd, parent);
                    currEnd = parent;
                    parent = parentMap.get(currEnd);
                }

            } else {
                // If no path is present from start to end, then we have disconnected graph.
                break;
            }
        }

        return minEdgeDeleteCOunt;
    }

    private static void deleteEdge(Map<Integer, List<Integer>> graph, Integer start, Integer end) {

        List<Integer> list = graph.get(start);
        list.remove(end);

    }

    // Get the path from the start node till end of the graph
    private static Map<Integer, Integer> bfs(Map<Integer, List<Integer>> graph, int start) {

        Map<Integer, Integer> parentMap = new HashMap<Integer, Integer>();
        List<Integer> visited = new ArrayList<Integer>();

        List<Integer> queue = new ArrayList<Integer>();
        int qStartIndex = 0;
        parentMap.put(start, -1);
        queue.add(start);

        while (qStartIndex < queue.size()) {
            int curr = queue.get(qStartIndex++);
            visited.add(curr);
            for (int k : graph.get(curr)) {
                if (!visited.contains(k)) {
                    queue.add(k);
                    if (!parentMap.containsKey(k)) {
                        parentMap.put(k, curr);
                    }
                }
            }
        }

        return parentMap;
    }
}