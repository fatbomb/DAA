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
ll const INF=1e9+7;

void dijkstra(ll source,ll dest,vector<pair<ll,ll>> g[], ll n)
{
    vector<ll> dist(n+1, INF);
    vector<bool> vis(n+1, false);
    vector<int> par(n+1,-2);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source]=0;
    par[source]=-1;
    bool fl=false;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(u==dest){
            break;
        }
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
                par[v] = u;
                
            }
        }
    }
    cout<<dist[dest]<<endl;
}
void caes(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> g[n+1];
    map<string,ll> mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=i;
        int m;
        cin>>m;
        while(m--){
            ll u,v;
            cin>>u>>v;
            g[i].push_back({u,v});
            g[u].push_back({i,v});

        }

    }
    ll p;
    cin>>p;
    while(p--){
        string a,b;
        cin>>a>>b;
        dijkstra(mp[a],mp[b],g,n);
    }

    
}
void somadhan(){
    ll t=1;
    cin>>t;
    while(t--){
        caes();
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}