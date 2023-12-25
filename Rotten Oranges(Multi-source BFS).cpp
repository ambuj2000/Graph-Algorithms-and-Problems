#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define w(t)  ll t; cin>>t; while(t--)
#define vi vector<int>
#define pb push_back

int RottenOranges(vector<vector<int> >&grid){
	int n=grid.size();
	int m=grid[0].size();
	int vis[n][m];
	int cntfresh=0;
	int cnt=0;
	queue<pair<pair<int,int>,int> >q;
	int tm=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grid[i][j]==2){
				q.push({{i,j},0});
				vis[i][j]=2;
			}
			else{
				vis[i][j]=0;
			}
			if(grid[i][j]==1)cntfresh++;
		}
	}
	int drow[]= {-1,0,1,0};
	int dcol[]= {0,1,0,-1};
    while(!q.empty()){
    	int r=q.front().first.first;
    	int c=q.front().first.second;
    	int t=q.front().second;
    	tm=max(tm,t);
    	q.pop();
    	for(int i=0;i<4;i++){
    		int nrow=r+drow[i];
    		int ncol=c+dcol[i];
    		if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
			&& vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
				q.push({{nrow,ncol},t+1});
				vis[nrow][ncol]=2;
				cnt++;
			}
		}
	}
	if(cnt!=cntfresh)return -1;
	return tm;
}


int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> >grid(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
		}
	}
   int ans=RottenOranges(grid);
	cout<<ans<<endl;
	
}
