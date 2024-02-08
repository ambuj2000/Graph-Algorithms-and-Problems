// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] 
// represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell,
// (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Example 1:

// heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explaination: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.This is better than the route of [1,2,2,2,5], 
// where the maximum absolute difference is 3.




class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int cur_dif=diff[row][col];
            
            
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int new_dif=max(cur_dif,abs(heights[nrow][ncol]-heights[row][col]));//it is taking max of current and next
                    //so we can maintain the same maximum distance if we traverse the grid bcz in this prblm
                    //we care about maxm absoluter difference so instead of taking abs diff of each grid we
                    //can directly maintain the maxm abs diff among all grid individual paths
                    
                    
                    if(new_dif<diff[nrow][ncol]){//checking if new_dif is less than infinity or 1e9 or if it is already visited and has more abs diff
                        diff[nrow][ncol]=new_dif;//if yes than put it into the diff 2d vector
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return diff[n-1][m-1];
    }
};
