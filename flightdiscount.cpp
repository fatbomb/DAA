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
ll Mi=INT_MIN;
void findMax(int v, vector<ll> &par,vector<pair<ll,ll>> g[]){
    if(v==-1 or par[v]==-1){
        return;
    }
    else{
        for(auto x:g[par[v]]){
            if(x.first==v){
                Mi=max(Mi,x.second);
            }
        }
        //cout<<Mi<<endl;
        findMax(par[v],par,g);
    }
}

void dijkstra(ll source,vector<pair<ll,ll>> g[],ll n){
    priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    vector<bool> vis(n+1,false);
    vector<ll> dis(n+1,INF);
    vector<ll> par(n+1,-1);
    pq.push({0,source});
    dis[source]=0;
    par[source]=-1;
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();
        if (vis[top.second]) continue ;
        for(auto x:g[top.second]){
            int u=x.first;
            ll w=dis[top.second]+x.second;
            if (!vis[u] &&  w < dis[u]){
                dis[u]=w;
                par[u]=top.second;
                pq.push({w,u});
            }
        }
        vis[top.second]=true;
            
    }
    findMax(n,par,g);
    ll x=dis[n]-Mi+(Mi/2);
    cout<<x<<endl;

}
void caes(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> g[n+1];
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});

    }
    dijkstra(1,g,n);

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