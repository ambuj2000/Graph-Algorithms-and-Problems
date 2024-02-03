// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two 
// integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . 
// You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list 
// of integers denoting shortest distance between each node and Source vertex S.
 

// Note: The Graph doesn't contain any negative weight cycle.(dijkstra cannot be used for -ve cycle)

 

// Example 1:

// Input:
// V = 2
// adj [] = {{{1, 9}}, {{0, 9}}}
// S = 0
// Output:
// 0 9
// Explanation:

// The source vertex is 0. Hence, the shortest 
// distance of node 0 is 0 and the shortest 
// distance from node 1 is 9.


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //take pq and distance vector while solving dijkstra's algo
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++){
            dist[i]=INT_MAX;
        }
        dist[S]=0;
        pq.push({0,S});//dist,src or node
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;//node->contains the pair of node and weight
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeweight=it[1];
                int adjNode=it[0];
                
                if(dis+edgeweight<dist[adjNode]){//if current dis is better than dis calc earlier
                    dist[adjNode]=dis+edgeweight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
    }
};
