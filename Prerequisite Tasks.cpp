// Using Topo sort
// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0
//   you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
// Input: 
// N = 4, P = 3
// prerequisites = {{1,0},{2,1},{3,2}}
// Output:
// Yes
// Explanation:
// To do task 1 you should have completed
// task 0, and to do task 2 you should 
// have finished task 1, and to do task 3 you 
// should have finished task 2. So it is possible.


class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    for(auto it:prerequisites){
	        adj[it.first].push_back(it.second);
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
	   if(topo.size()==N)return true;
	   return false;
	}
};
