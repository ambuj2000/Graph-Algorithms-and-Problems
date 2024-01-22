//Using topo sort
// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks,
//   for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.

//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
         vector<int>adj[N];
	    for(auto it:prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int>topo;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node);
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	   if(topo.size()==N)return topo;
	   return {};
	}
};
