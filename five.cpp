// remove minimum number of edges to disconnect 2 vertices.
// http://myitlearnings.com/from-a-given-graph-delete-minimum-number-of-edges-such-that-there-is-no-path-from-start-node-to-end-node/

#include <bits/stdc++.h>

using namespace std;

// Get the path from the start node till end of the graph
map<int, int> bfs(map<int, set<int>> &graph, int src) {
    map<int, int> parentMap;
    set<int> vis;
    queue<int> q;
    q.push(src);
    parentMap[src] = -1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis.insert(u);
        for(auto it : graph[u]) {
            if(vis.find(it) == vis.end()) {
                q.push(it);
                if(parentMap.find(it) == parentMap.end())
                    parentMap[it] = u;
            }
        }
    }
    return parentMap;
}


int removeMinEdges(vector<vector<int>> &edges, int src, int dest) {

    map<int, set<int>> graph;

    for(auto it : edges) {
        graph[it[0]].insert(it[1]);
        graph[it[1]].insert(it[0]);
    }
    int minEdgesDelCount = 0;
    while(true) {
        map<int, int> parentMap = bfs(graph, src);

        if(parentMap.find(dest) != parentMap.end()) {
            minEdgesDelCount++;
            int parent = parentMap[dest];
            int currEnd = dest;
            while(parent != -1) {
                graph[parent].erase(currEnd);
                graph[currEnd].erase(parent);
                currEnd = parent;
                parent = parentMap[currEnd];
            }
        }
        else
            break;
    }
    return minEdgesDelCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m;i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    int ans = removeMinEdges(edges, 1, n);
    cout << ans << "\n";
}