// AlgoU CONTEST PROBLEM

// You are the newly elected Chief Minister of the state. As promised in your rally, you decided to provide water to all the cities in your state.
// Your state is situated in a hilly area. There are canals that connect 2 cities. 
// Sending water downhill is easy, but sending water uphill requires dam construction. 
// It costs X dollars to construct a dam. Note that a dam can be built only on existing canals.
// You need to find the total cost to complete your promise.

// The city was carefully planned, and there are no loops of canals. This means there is only one way to reach a city from the city 1.
// You can consider an infinite water supply in the city 1.
  
// INPUT
// The first line contains 2
// integer N and X, denoting the number of cities in your state and the cost to build a dam, respectively.
// The next N lines contain 2 integers a and b, denoting a canal between them, and a is located at a higher altitude than b.

// OUTPUT
// Output a single integer denoting the total amount to build dams such that each city gets a water supply.

// EXAMPLE
// Sample 1 INPUT:
// 7 5
// 1 2
// 3 1
// 2 4
// 5 4
// 3 6
// 6 7
// Sample 1 OUTPUT:
// 10

// Note
// In the first test case, you will need to construct 2 dams. First on the canal connecting 5 and 4
// ,and the other on the canal connecting 1 and 3.


// Code:

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define w(t)  ll t; cin>>t; while(t--)
#define vi vector<int>
#define pb push_back


void dfs(int node,vector<vector<pair<int,int> > >& adj, vector<int>& vis,ll &sum){
	
	vis[node]=1;
	for(auto & it : adj[node]){
		if(!vis[it.first]){
			sum+=it.second;//adding the x value which is the cost of building the damn
		    dfs(it.first,adj,vis,sum);
		}
	}
}


int main() {
 int n,x; cin>>n>>x;
 vector<vector<pair<int,int>>>adj(n+1);
 ll sum=0;
  vector<int>vis(n+1);
 int a,b;
 for(int i=0;i<n-1;i++){
 	cin>>a>>b;
 	adj[a].push_back({b,0});//sending water downhill is easy so 0 costs
 	adj[b].push_back({a,x});//sending water uphill requires dam x costs
 }  
 dfs(1,adj,vis,sum);
 cout<<sum<<endl;
}



