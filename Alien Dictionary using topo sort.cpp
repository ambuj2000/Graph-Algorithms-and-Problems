// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary.
// Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output 
// will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

// Example 1:

// Input: 
// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}
// Output:
// 1
// Explanation:
// Here order of characters is 
// 'b', 'd', 'a', 'c' Note that words are sorted 
// and in the given language "baa" comes before 
// "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.


//NOTE: if any/single  different alphabet is found different between two comparing string then move for
//to check among another pair of the strings


//exception- when the order is not possible
//abcd-s1
//abc-s2
// In this case order is not possible because the largest string is before the shortest string
//then the order is not possible
// and  also for cycle the order is not possible
//like abc-s1
//bat-s2
//ade-s3    a->b->a//not possible


class Solution{
    private:
     vector<int> topoSort(int N, vector<int> adj[]) {
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
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int  i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){//note that here s1 will be the first string while 
                //comparing pairwise s1 and s2 
                adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                break;
                }
            }
        }
        vector<int>topo=topoSort(K,adj);
        string ans="";
        for(auto it:topo){
            ans=ans+char(it+'a');
        }
        return ans;
    }
};
