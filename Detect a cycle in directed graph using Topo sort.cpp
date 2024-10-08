//Note: in topo sort if the linear ordering is of n size then there is no cycle
// bcoz topo is only used in DAG

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(V, 0); 
	    for(int i = 0;i<V;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<V;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt=0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	   if(cnt==V)return false;
	   return true;
    }
};
