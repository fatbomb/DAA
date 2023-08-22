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
const int INF=1e9+7;
bool belmanford(int V, vector<vector<int>> &edges, int s,vector<int> &h)
{
    vector<int> d(V+1, INF);
    d[s] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (d[u] != INF && d[u] + wt < d[v])
            {
                d[v] = d[u] + wt;
            }
        }
    }
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (d[u] != INF && d[u] + wt < d[v])
        {
            cout<<"Negetaive cycle present";
            return false;
        }
    }
    h=d;
    return true;
}
void printdistance(vector<vector<int>> &dist,int n){
    for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                // if(i==j){
                //     cout<<"0 ";
                // }
                if(dist[i][j]==INF){
                    cout<<"INF ";
                }
                else{
                    cout<<dist[i][j]<<" ";
                } 

            }
            cout<<endl;
        }
}
void dijkstra(int source,int n,vector<int> &dist,vector<pair<int,int>> g[])
{
    vector<bool> vis(n+2, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source]=0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto child : g[u])
        {
            if(vis[child.first]){
                continue;
            }
            ll v = child.first;
            ll wt = child.second;
            //cout<<"2\n";
            //cout<<v<<" "<<dist[u]+wt<<"\n";
            if (dist[u] + wt < dist[v])
            {
                dist[v] = d + wt;
                pq.push({dist[v], v});
                
            }
        }
    }
    // for(auto d:dist){
    //     cout<<d<<" ";
    // }
    // cout<<endl;
    return;
}

void caes(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    vector<int> h(n+2, 0);
    vector<pair<int,int>> g[n+1];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        
    }
    for(int i=1;i<=n;i++){
        edges.push_back({n+1,i,0});
    }
    if(!belmanford(n+1,edges,n+1,h)){
        //printdistance(dist,n);
        return;
    }
    // for(auto d:h){
    //     cout<<d<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<m;i++){
        int d=edges[i][2]+h[edges[i][0]]-h[edges[i][1]];
        g[edges[i][0]].push_back({edges[i][1],d});
        //cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<d<<endl;
    }
    for(int i=1;i<=n;i++){
        vector<int> V(n+1,INF);
        dijkstra(i,n,V,g);
        for(int j=1;j<=n;j++){
            dist[i][j]=V[j]-h[i]+h[j];
        }
    }
    printdistance(dist,n);

    /*code*/
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