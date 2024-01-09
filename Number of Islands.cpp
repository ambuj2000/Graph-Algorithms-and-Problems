
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