//Prims algo helps to find MST(minimum sum of edges such that every node is reachable considering n nodes and n-1 edges)

// Given a weighted, undirected and connected graph of V vertices and E edges.
//The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
// Given adjacency list adj as input parameters .
// Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge 
//and the second integer denotes the edge weight.



// To clarify, an MST is a tree that spans all the vertices of the graph, hence the term "spanning tree." 
// It's "minimum" in the sense that the total weight of the edges in the tree is minimized, but it
// still maintains the property of a tree, which means it has no cycles.

// If an MST did contain a cycle, it wouldn't be a tree, as trees, by definition, cannot contain cycles.
// Therefore, by definition, an MST does not form a cycle

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst and we do not add it if it forms cycle or lies in differnt component
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};


int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}
