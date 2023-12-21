#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
       void dfs(vector<vector<int>>&image,vector<vector<int>>&ans,int row,
       int col,int newColor,int drow[],int dcol[],int initcolor){
           ans[row][col]=newColor;
           int n=image.size();
           int m=image[0].size();
           for(int i=0;i<4;i++){
               int dirrow=row+drow[i];
               int dircol=col+dcol[i];
               if(dirrow>=0 && dirrow<n && dircol>=0 && dircol<m
               && image[dirrow][dircol]==initcolor &&
               ans[dirrow][dircol]!=newColor){
                   dfs(image,ans,dirrow,dircol,newColor,drow,dcol,initcolor);
               }
           }
       }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initcolor=image[sr][sc];
        vector<vector<int>>ans=image;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        dfs(image,ans,sr,sc,newColor,drow,dcol,initcolor);
        return ans;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
