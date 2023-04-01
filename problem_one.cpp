// Nearest meeting cell of 2 nodes

#include<bits/stdc++.h> 
using namespace std;

void djikstra(vector<int> adj[], int n, int st, vector<int> &dis) {
    for(int i=0; i<n; i++)
        dis[i] = INT_MAX;
    dis[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto it : adj[u]) {
            if(dis[it] > dis[u] + 1) {
                dis[it] = dis[u] + 1;
                q.push(it);
            }
        }
    }
    // for(int i=0; i<n; i++)
    //     cout << dis[i] << " ";
    // cout << "\n";
}

void solve(int n, int A, int B, vector<int> edges) {
    int i;
    vector<int> adj[n];
    for(i=0; i<n; i++) {
        if(edges[i] != -1)
            adj[i].push_back(edges[i]);
    }
    vector<int> dis1(n);
    vector<int> dis2(n);
    djikstra(adj, n, A, dis1);
    djikstra(adj, n, B, dis2);
    int node = -1, dis = INT_MAX;
    for(i=0;i<n;i++) {
        if(dis1[i] == INT_MAX || dis2[i] == INT_MAX)
            continue;
        if(dis > dis1[i]+dis2[i]) {
            dis = dis1[i] + dis2[i];
            node = i;
        }
    }
    cout << node << "\n";
}
int main() {
    int n;
    cin >> n;
    vector<int> edges(n);
    for(int i=0; i<n; i++)
        cin >> edges[i];
    int A, B;
    cin >> A >> B;
    solve(n, A, B, edges);
    return 0;
}

/*
11
4 4 1 5 3 9 8 8 0 8 -1
2 9
*/

