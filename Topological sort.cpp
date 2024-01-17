//DAG -Linear ordering of vertices such that if there is edge b/w u and v, u appears before v in that ordering

//Topo sort using DFS
class Solution
{
    private:
       void dfs(int node,int vis[],stack<int>&s,vector<int>adj[]){
           vis[node]=1;
           for(auto it:adj[node]){
               if(!vis[it]){
                   dfs(it,vis,s,adj);
               }
           }
           s.push(node);
       }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,s,adj);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};



//Topo sort using BFS
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	        
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	    return topo;
	}
};
