#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
bool bfs(int src, vector<int>adj[], int vis[]){
vis[src]=1;
queue<pair<int,int>>q;  //note: here we take queue pair bcoz we need both parent and child note to detect the cycle!
q.push({src,-1});  //because there will be no parent of the src node
while(!q.empty()){
int node=q.front().first;
int parent=q.front().second;
q.pop();
for(auto it:adj[node]){
    if(!vis[it]){
       vis[it]=1;
       q.push({it,node});
    }else if(parent!=it){
        return true;
    }
}
}
return false;
}


public:
bool isCycle(int V, vector<int>adj[]){
int vis[V]={0};
for(int i=0;i<V;i++){    //Here we are checking cycles if there are non-connected components like for e.g--> 1-2-3  & 4-5-8 
  if(!vis[i]){
     if(bfs(i,adj,vis))
          return true;
  }
}
  return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
