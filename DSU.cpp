/*
DisjointSet Union Problem
https://www.codechef.com/LP3TO401/problems/DSUBAGS
*/

#include<bits/stdc++.h> 
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define N 100009

vector<int> ar(N), sz(N);
int bags;

int root(int n) {
    while(ar[n] != n) {
        ar[n] = ar[ar[n]];
        n=ar[n];
    }
    return ar[n];
}

void DSunion(int a, int b) {
    int root_A = root(a);
    int root_B = root(b);
    if(root_A == root_B)
        return;
    bags--;
    if(sz[root_A] < sz[root_B ])
    {
        ar[ root_A ] = ar[root_B];
        sz[root_B] += sz[root_A];
    }
    else
    {
        ar[ root_B ] = ar[root_A];
        sz[root_A] += sz[root_B];
    }
}

void solve() {
    int i, j;
    int n, q;
    cin >> n >> q;
    for(i=1; i<=n; i++) {
        ar[i]=i;
        sz[i]=1;
    }
    bags = n;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b;
            cin >> a >> b;
            DSunion(a, b);
        }
        else if(type == 2) {
            int a, b;
            cin >> a >> b;
            if(root(a) == root(b)) {
                cout<<"YES\n";
            }
            else    
                cout<<"NO\n";
        }
        else {
            cout << bags << "\n";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t=1;
    //cin >> t;
    for(int i=1;i<=t;i++) {
        // cout<<"Case #" << i <<": ";
        solve();
    }
    return 0;
}

/*
3 8 
2 1 2 
3 
1 1 2 
3 
2 1 2 
1 2 3 
3 
2 1 3
*/