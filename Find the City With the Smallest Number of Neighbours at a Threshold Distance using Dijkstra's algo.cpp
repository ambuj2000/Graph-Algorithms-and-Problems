// You don't need to read input or print anything. Your task is to complete the function findCity( ) which takes a No of nodes N 
//   and vector of edges and ThresHold Distance. and Return the city with the smallest number of cities that are reachable through
// some path and whose distance is at most Threshold Distance, If there are multiple such cities, return the city with the greatest number.

// Expected Time Complexity: O(V^2 + EVlogV)
// Expected Auxiliary Space:  O(N^3)
// Input Format: 
// N=4, M=4, 
// edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], 
// distanceThreshold = 4

// Result: 3
// Explanation: 
// The adjacent cities for each city at a distanceThreshold are =
// City 0 →[City 1, City 2]
// City 1 →[City 0, City 2, City 3]
// City 2 →[City 0, City 1, City 3]
// City 3 →[City 1, City 2]
// Here, City 0 and City 3 have a minimum number of cities 
// i.e. 2 within distanceThreshold. So, the result will be the 
// city with the largest number. So, the answer is City 3.





// User function Template for C++
class Solution {
void dijkstra(int n,int m,vector<pair<int,int>> adj[],vector<int> &dist,int src,int threshold){
          dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({src,0});
    while(!pq.empty()){
        int node=pq.top().first;
        int dis=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adjNode=it.first;
            int edgeW=it.second;
            if(dis+edgeW<dist[adjNode]){
                dist[adjNode]=dis+edgeW;
                pq.push({adjNode,dist[adjNode]});
            }
        }
    }
    }
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
     
      int maxi = INT_MAX; 
      int result = -1;   
      for(int i = 0; i < n; i++){
        vector<int> dist(n,1e9);
        dijkstra(n, m, adj, dist, i, distanceThreshold);
        int cnt = 0;
        for(int j = 0; j < dist.size(); j++){
            if(dist[j] <= distanceThreshold){
                cnt++;
            }
        }
        if(cnt <= maxi){
            maxi = cnt;
            result = i;
        }
    }
    return result;
 }
};
