// You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt.
//   This area is in the shape of a circle with the center as the location of the bomb.

// The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote
// the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

// You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
//   These bombs will further detonate the bombs that lie in their ranges.

// Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

// Example 1:


// Input: bombs = [[2,1,3],[6,1,4]]
// Output: 2
// Explanation:
// The above figure shows the positions and ranges of the 2 bombs.
// If we detonate the left bomb, the right bomb will not be affected.
// But if we detonate the right bomb, both bombs will be detonated.
// So the maximum bombs that can be detonated is max(1, 2) = 2.


//Approach-1 (Using DFS)
class Solution {
public:
    typedef long long LL;
    void DFS(int u, unordered_set<int> & visited, unordered_map<int, vector<int>> &adj) {
        
        visited.insert(u);
        
        for(int &v : adj[u]) {
            if(visited.find(v) == visited.end()) { //Not visited
                DFS(v, visited, adj);
            }
        }

    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        unordered_set<int> visited;
        
        for(int i = 0; i<n; i++) {
            DFS(i, visited, adj);
            int count = visited.size();
            result = max(result, count);
            visited.clear();
        }
        
        return result;
        
    }
};


//Approach-2 (Using BFS)
class Solution {
public:
    typedef long long LL;
    int BFS(int u, unordered_map<int, vector<int>> &adj) {
        unordered_set<int> visited;
        queue<int> que;
        que.push(u);
        visited.insert(u);

        while(!que.empty()) {
            
            int temp = que.front();
            que.pop();
            
            for(int &v : adj[temp]) {
                
                if(visited.find(v) == visited.end()) {
                    que.push(v);
                    visited.insert(v);
                }
                
            }
            
            
        }
        
        return visited.size();
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                
                //Make a directed edge from i to j if i can detonate j as well
                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
                
            }
        }
        
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            int count = BFS(i, adj);
            result = max(result, count);
        }
        
        return result;
        
    }
};
