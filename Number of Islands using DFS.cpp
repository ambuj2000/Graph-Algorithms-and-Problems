
#include <bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>&grid,int row,int col){
        grid[row][col]='0';      // Transform land into water so we don't revisit this cell.
        int drow[]={-1,-1,-1,0,0,1,1,1};
        int dcol[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<8;i++){
            int rowdir=row+drow[i];
            int coldir=col+dcol[i];
            if(rowdir>=0 && rowdir<grid.size() && coldir>=0 && coldir<grid[0].size() && grid[rowdir][coldir]=='1')
            dfs(grid,rowdir,coldir);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]=='1'){
                    dfs(grid,row,col);
                    cnt++;
                }
            }
        }
        return cnt;
    }

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}





//USING BFS


class Solution {
  private: 
  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {
      // mark it visited
      vis[row][col] = 1; 
      queue<pair<int,int>> q;
      // push the node in queue
      q.push({row, col}); 
      int n = grid.size(); 
      int m = grid[0].size(); 
      
      // until the queue becomes empty
      while(!q.empty()) {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
          
          // traverse in the neighbours and mark them if its a land 
          for(int delrow = -1; delrow<=1;delrow++) {
              for(int delcol = -1; delcol <= 1; delcol++) {
                  int nrow = row + delrow; 
                  int ncol = col + delcol; 
                  // neighbour row and column is valid, and is an unvisited land
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                  && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                      vis[nrow][ncol] = 1; 
                      q.push({nrow, ncol}); 
                  }
              }
          }
      }
  }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        // create visited array and initialise to 0
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt = 0; 
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < m ;col++) {
                // if not visited and is a land
                if(!vis[row][col] && grid[row][col] == '1') {
                    cnt++; 
                    bfs(row, col, vis, grid); 
                }
            }
        }
        return cnt; 
    }
};
