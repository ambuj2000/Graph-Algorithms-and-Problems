```
// This is the dfs code dfs->follows the recursive approach first goes in depth forms the recursive tree and comes back

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define w(t)  ll t; cin>>t; while(t--)
#define vi vector<int>
#define pb push_back

void dfs(vector<vector<int>>& adj, int src, vector<bool>& vis) {
    cout << src << " ";
    vis[src] = true;
    for (auto neighbor : adj[src]) {
        if (!vis[neighbor]) {
            dfs(adj, neighbor, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> vis(n + 1, false);
    dfs(adj, 1, vis);

    return 0;
}



```
