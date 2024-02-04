class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>dist(V,INT_MAX);
        
        st.insert({0,S});//set with dist and source node
        dist[S]=0;
        
        while(!st.empty()){
            auto it=*(st.begin());//gives the first value of the set
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edgW=it[1];
                
                if(dis+edgW<dist[adjNode]){
                    //erase if it existed
                    if(dist[adjNode]!=INT_MAX)
                        st.erase({dist[adjNode],adjNode});
                        
                        dist[adjNode]=dis+edgW;
                        st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
