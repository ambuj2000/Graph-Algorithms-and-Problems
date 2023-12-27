// Given an unweighted graph consisting of N nodes and M bidirectional edges. Print all nodes that could be part of any shortest path from node 1 to node N
//  in ascending order. If node N is not reachable from node 1, then print −1. 
// 2≤N≤10^5 
// 1≤M≤2×10^5
// INPUT
// The first line contains two integers N and M- the number of nodes and edges. The next M lines describe two integers uand v
//  denoting there exist an edge between node u and v.

// OUTPUT
// Print all nodes which could be part of any shortest from node 1 to N.
// If it is not possible to reach node N then print −1.
// EXAMPLE
// Sample 1 INPUT:
// 6 7
// 1 2
// 1 3
// 2 4
// 4 5
// 5 6
// 3 6
// 2 6

// Sample 1 OUTPUT:
// 1 2 3 6 


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define w(t)  ll t; cin>>t; while(t--)
#define vi vector<int>
#define pb push_back

vector<int> bfs(int src,vector<vector<int> >& adj) {
    queue<int> q;
    q.push(src);
    vector<bool> vis(adj.size(), false);
    vector<int> dist(adj.size(), INT_MAX);

    dist[src] = 0;
    vis[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < adj[u].size(); i++) {
            if (vis[adj[u][i]] == false) {
                vis[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                q.push(adj[u][i]);
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>dist1,distN;
   dist1=bfs(1,adj);
   distN=bfs(n,adj);

if(dist1[n]==INT_MAX){
	cout<<-1<<endl;
}else{
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(dist1[i]+distN[i]==dist1[n]){
			ans.push_back(i);
		}
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}
}


