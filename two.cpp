// Longest cycle in a graph

#include<bits/stdc++.h> 
using namespace std;


void dfs(vector<int> adj[], int node, vector<int>& vis, int& ans) {
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it] == 0)
            dfs(adj, it, vis, ans);
        else if(vis[it] == 2)
            continue;
        else {
            int st=it, curr=0;
            while(true) {
                curr++;
                st=adj[st][0];
                if(st == it)
                    break;
            }
            ans = max(ans, curr);
        }
    }
    vis[node]=2;
}
int longestCycle(vector<int>& edges) {
    int n=edges.size();
    vector<int> adj[n];
    for(int i=0;i<n;i++) {
        if(edges[i]!=-1)
            adj[i].push_back(edges[i]);
    }
    vector<int> vis(n, 0);
    int ans =-1;
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs(adj, i, vis, ans);
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> edges(n);
    for(int i=0; i<n; i++)
        cin >> edges[i];
    cout << longestCycle(edges) << "\n";
    return 0;
}

/*
11
4 4 1 5 3 9 8 8 0 8 -1

23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
(6)
*/

