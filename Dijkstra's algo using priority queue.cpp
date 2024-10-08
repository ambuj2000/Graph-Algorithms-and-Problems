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

// Example 2:
// V = 3, E = 3

// adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}

// S = 2

// Output:

// 4 3 0

// Explanation: 

// For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. 
// So, the Shortest path from 2 to 0 is 4.

// The shortest distance from 0 to 1 is 1.


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

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

T.C-->E log V
