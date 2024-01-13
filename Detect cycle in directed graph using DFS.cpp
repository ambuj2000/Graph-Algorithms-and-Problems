class Solution {
    private:
    bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            //COND 1:when the node is not visited 
            if(!vis[it]){
               if(dfs(it,adj,vis,pathvis)==true) return true;
            }
            //COND 2:if the node has been previously visited
            //but it has to be visited on the same path and not on the earlier path
            //bcoz there are cases when directed edge from two diff direction also 
            //forms a cycle so to exclude that condn we take pathvis array.
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;//need to make it 0 while returning when we
        //do not encounter any node further or no cycle
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true)return true;
            }
        }
        return false;
    }
};
