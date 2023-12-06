//BFS algorithm-level order traversal matlab first level gets exceuted then second then third similar to queue-FIFO so use fifo

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define w(t)  ll t; cin>>t; while(t--)
#define vi vector<int>
#define pb push_back

void bfs(vector<vector<int> >&adj,int src){
	queue<int>q;
	q.push(src);
	vector<bool>vis(adj.size(),false);
	vis[src]=true;
	while(!q.empty()){
		int u=q.front();
		cout<<u<<" ";
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			if(vis[adj[u][i]]==false){
				q.push(adj[u][i]);
				vis[adj[u][i]]=true;
			}
		}
	}

}

int main() {
int n,m;
cin>>n>>m;
vector<vector<int> >adj(n+1);
for(int i=0;i<m;i++){
	int x,y;
	cin>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);
}
bfs(adj,1);
}





