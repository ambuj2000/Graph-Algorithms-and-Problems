//topo sort means if graph has directed edge between u->v, then u will always come before u
//Topo sort is the linear ordering of 'n' vertices(remember::strictly the size of topo sort should be of n)
// this can be solve using indegree concept also with help of kahn's algo - abit modification of BFS
//here sorting happens based on number of indegrees a node has 

//1. Insert all nodes with indegree 0 into the queue 
//2. Then take them out of the queue (before that store the node in vector) & 
//just reduce the indegree of the adjacent nodes(and if the adjacent nodes have indegree 0 then follow the same steps)
//3. finally return the vector as ans

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
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
	    vector<int> topo;
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
	    return topo;
	}
};



int main()
{

    	vector<int> adj[6];
    	adj[5].push_back(2);
    	adj[5].push_back(0);
    	adj[4].push_back(0);
    	adj[4].push_back(1);
    	adj[3].push_back(1);
    	adj[2].push_back(3);

    	Solution obj;
    	vector<int> v=obj.topo(6, adj);
    	for(auto it:v)
    	cout<<it<<" ";
    

    return 0;
}



