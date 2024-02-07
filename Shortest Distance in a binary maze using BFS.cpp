// Given a n * m matrix grid where each element can either be 0 or 1.
// You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 

// If the path is not possible between source cell and destination cell, then return -1.

// Note : You can move into an adjacent cell if that adjacent cell is filled with element 1.
// Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.
//   The source and destination cell are based on the zero based indexing. The destination cell should be 1.

// Example 1:

// Input:
// grid[][] = {{1, 1, 1, 1},
//             {1, 1, 0, 1},
//             {1, 1, 1, 1},
//             {1, 1, 0, 0},
//             {1, 0, 0, 1}}
// source = {0, 1}
// destination = {2, 2}
// Output:
// 3
// Explanation:
// 1 1 1 1
// 1 1 0 1
// 1 1 1 1
// 1 1 0 0
// 1 0 0 1
// The highlighted part in the matrix denotes the 
// shortest path from source to destination cell.



class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX)); //Creating another 2d vector to store dist
        dist[source.first][source.second]=0;//given source in the form of coordinates like (1,0)
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first,source.second}});//{dist,{1,0}}--1,0 is just an example
        
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.second.first;
            int c=it.second.second;
            int dis=it.first;
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                
                if(newr>=0 && newr<n && newc>=0 && newc<m
                 && dis+1<dist[newr][newc] && grid[newr][newc]==1){
                     if(newr==destination.first && newc==destination.second)
                            return dis+1;
                            dist[newr][newc]=dis+1;
                            q.push({1+dis,{newr,newc}});
                 }
            }
        }
        if(source.first==destination.first && source.second==destination.second)
                  return 0;//checking if src and dest are equal
        return -1;
                         
                     }  
};
