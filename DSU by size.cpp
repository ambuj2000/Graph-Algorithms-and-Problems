// Until now, we have learned union by rank, the findPar() function, 
// and the path compression technique. Now, if we again carefully observe, after applying path compression the rank
// of the graphs becomes distorted. So, rather than storing the rank, we can just store the size of the components for
// comparing which component is greater or smaller.

// So, here comes the concept of Union by size.

#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // void unionByRank(int u, int v) {
    //     int ulp_u = findUPar(u);
    //     int ulp_v = findUPar(v);
    //     if (ulp_u == ulp_v) return;
    //     if (rank[ulp_u] < rank[ulp_v]) {
    //         parent[ulp_u] = ulp_v;
    //     }
    //     else if (rank[ulp_v] < rank[ulp_u]) {
    //         parent[ulp_v] = ulp_u;
    //     }
    //     else {
    //         parent[ulp_v] = ulp_u;
    //         rank[ulp_u]++;
    //     }
    // }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
Output:
Not Same
Same

Time Complexity:  The time complexity is O(4) which is very small and close to 1. So, we can consider 4 as a constant.
