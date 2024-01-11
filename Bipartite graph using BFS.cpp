//Bipartite means adjacent node have 2 different color-->here I am considering 0 and 1 and two different color
//NOTE: Linear graphs with no cycles are always Bipartite & cyclic graph with even number of nodes are also always Bipartite.

class Solution {
    private:
    bool bfs(int src,vector<int> adj[],vector<int>& color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto nbr:adj[curr]){
                 //if the adjacent node is not yet colored you will give oppo color of node
                if(color[nbr] == -1){
                    color[nbr] = !color[curr];
                    q.push(nbr);
                }
                //else if adjacent node has same color
                   //someone did color it then hence it is not bipartite (odd length cycle)
                else if(color[curr]==color[nbr]) return false;
            }
        }
        return true;
    }
       
public:
    bool isBipartite(int V, vector<int>adj[]){
        // Code here
        vector<int> color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i] == -1){
               if(bfs(i,adj,color) == false) return false;
                //if(dfs(i,adj,color,0) == false) return false;
            }
        }
        return true;
    }

};
