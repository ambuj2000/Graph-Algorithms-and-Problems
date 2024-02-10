// There are n cities and m edges connected by some number of flights. 
// You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Note: The price from city A to B may be different From the price from city B to A.

// Example 1:
// Input:
// n = 4
// flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
// src = 0
// dst = 3
// k = 1
// Output:
// 700
// Explanation:
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.



//solving using Dijkstra's algo but using queue instead of PQ
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;//queue-{stops,{node,dist}}(instead of pq because pq stores in form of sorting the dist)
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);//dist array with initialising INT_MAX at first
        dist[src]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            
            if(stops>K)continue;
            
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edw=it.second;//edgeweight
                
                if(dis+edw<dist[adjNode] && stops<=K){
                    dist[adjNode]=dis+edw;
                    q.push({stops+1,{adjNode,dis+edw}});
                }
            }
            
        }
        
        
        if(dist[dst]==1e9)return -1;
        return dist[dst];
    }
};

T.C=O(E)--Edges(flights)
