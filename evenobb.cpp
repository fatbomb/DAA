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

void aro_govire_jao(ll v,vector<pair<ll,ll>> g[],vector<ll> &mi, ll par, ll wt,ll n){


    for(pair<ll,ll> baccha:g[v]){

        if(baccha.first==par){
            continue;
        }
        if(v==n and wt%2==0){
            mi.push_back(wt);
        }
        aro_govire_jao(baccha.first,g,mi,v,wt+baccha.second,n);

    }
}

void caes(int n, int m){
    
}
void somadhan(){
    ll t=1;
    //cin>>t;
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        cout<<n<<" "<<m<<endl;
        vector<pair<ll,ll>> g[n+4];
        for(int i=0;i<m;i++){
            int u,v,w; 
            scanf("%d %d %d",&u,&v,&w);
            cout<<u<<" "<<v<<" "<<w<<endl;
            //g[u].push_back({v,w});
            //g[v].push_back({u,w});

        }    
        vector<ll> mi;
        aro_govire_jao(1,g,mi,-1,0,n);
        if(mi.size()==0){
            cout<<"-1\n";
            continue;
        }
        sort(mi.begin(),mi.end());
        cout<<mi[0]<<endl;
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}