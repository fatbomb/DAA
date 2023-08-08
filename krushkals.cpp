//Proud to be a Bangali :)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define endl "\n" 

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define arektu_row_na_somoy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const N=2e5+7;
class DSU{
    vector<int> rank,parent,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }

    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void UnionByRank(int u,int v){
        int pu = findUPar(u),pv = findUPar(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pv] = pu ;
            rank[pu]++;
        }

    }
    void UnionBySize(int u,int v){
        int pu = findUPar(u),pv = findUPar(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }

};
int SpanningTree(int v, vector<pair<int,int>> g[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<v;i++){
        for (auto it :g[i]) {
            int adjNode=it.first;
            int wt=it.second;
            int node=i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    DSU dsu(v);
    int sum=0;
    for(auto it :edges){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;

        if(dsu.findUPar(u)!=dsu.findUPar(v)){
            sum+=wt;
            dsu.UnionBySize(u,v);
        }
    }
    return sum;
}

void caes(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(make_pair(b, c));
        g[b].emplace_back(make_pair(a, c));
    }
    int sum = SpanningTree(n, g);
    cout << sum << endl;
}
void somadhan(){
    ll t=1;
    //cin>>t;
    while(t--){
        caes();
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}