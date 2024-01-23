#include<bits/stdc++.h>
 using namespace std;
 #define maxn 1000000
 
 int par[maxn];
 
 int find_leader(int v) { return par[v]<0 ? v : (par[v]=find_leader(par[v])); }
 
 void merge(int x,int y){
     if((x=find_leader(x)) == (y=find_leader(y)) ) return;
     if(par[y]<par[x])// balancing the depth of the tree
         swap(x,y);
     if(par[x]==par[y])
         par[x]--;//depth increases by 1 if the depth of both groups are same
      par[y]=x;
 }
 
 vector<pair<int,pair<int,int> > > edges; // first element of pair is weight of the edge
                                         // second element of pair is pair of end nodes
 vector<pair<pair<int,int>,pair<int,int> > > queries;
 
 int main(){
    int n,m,q;
    cin>>n>>m;
    for(int i=0;i<m;i++){
         int x,y,w;
         cin>>x>>y>>w;
         edges.push_back({w,{x,y}});
    }
    cin>>q;
    while(q--){
         int u,v,w;
         cin>>u>>v>>w;
         queries.push_back({{w,i},{u,v}});
    }
    sort(edges.begin(),edges.end());
    sort(queries.begin(),queries.end());
    int ans[q];
    int p=0;//pointer for processing edges
    for(int i=0;i<q;i++){
         while(p<m and edges[p].first<=queries[i].first.first){
             merge(edges[p].second.first,edges[p].second.second);
             p++;
         }
         if(find_leader(queries[i].second.first)==find_leader(queries[i].second.second))
         ans[queries[i].first.second]=1;
         else
         ans[queries[i].first.second]=0;
    }
    
    for(int i=0;i<q;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
 }
