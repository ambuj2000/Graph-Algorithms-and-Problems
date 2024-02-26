// The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
// The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. 
// If Matrix[i][j]=-1, it means there is no edge from i to j.
// Do it in-place.


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e9;
	            }
	        }
	}
	 
	for(int k=0;k<n;k++){
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);//meaning ki  e.g 1-3 ka distance first 0 include karenge path mein like 1-0 + 0-3 same way
			//2-3 ka distance so 2-0+0-3 same way for all pairs we need to calculate.
	    }
	}
	}
	
    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    if(matrix[i][j]==1e9){
    matrix[i][j]=-1;
    }
    }
    }
	
	}
};
