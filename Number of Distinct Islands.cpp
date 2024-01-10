class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>>&vis,
    vector<vector<int>>&grid,vector<pair<int,int>>&vec,int row0,int col0){
        vis[row][col]=1;//here row0 and col0 is the base from where we can subtract to get result
        vec.push_back({row-row0,col-col0});
        //here the algo is simple whenever we in grid we
        //subtract base from the coordinate and then store the 
        //result in the set of vector pair and automatically the same coordinate 
        //pair will not be stored and this way we can return size of the set for distinct islands
        //Input:
// grid[][] = {{1, 1, 0, 1, 1},
//             {1, 0, 0, 0, 0},
//             {0, 0, 0, 0, 1},
//             {1, 1, 0, 1, 1}}
// Output:
// 3
// Explanation:
// grid[][] = {{1, 1, 0, 1, 1}, 
//             {1, 0, 0, 0, 0}, 
//             {0, 0, 0, 0, 1}, 
//             {1, 1, 0, 1, 1}}

// here for coordinate (0,3) & (0,4) --> (3,0) & (3,1) it is the same coordinate
// if we subtract the base coordinate i.e for first (0,3) will be base coordinate
// for second (3,0) will be base coordinate and if we subtract (0,3) in first
// it will give (0,0) & (0,1) and if we subtract (3,0) base coordinate in second
//it will result the same (0,0) & (0,1) so thats why store in set of vector pair
         int n=grid.size();
        int m=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
          int nrow=row+drow[i];
          int ncol=col+dcol[i];
          
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
          && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
              dfs(nrow,ncol,vis,grid,vec,row0,col0);
              
          }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis,grid,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
