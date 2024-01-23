//if any node is part of the cycle or in a cycle then it is not considered as safe nodes
//because its every possible path starting from that node does not leads to a terminal node.




class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>adjRev[V];
        int indegree[V]={0};
        for(int i=0;i<V;i++){
            //i->it
            //it->i
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>safenodes;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
        }
    }
    sort(safenodes.begin(),safenodes.end());
    return safenodes;
    }
    
};
