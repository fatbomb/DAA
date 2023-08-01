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

ll const N=1e3+7;
int x=0;
bool vis[N];
ll d[N],h[N];
int cnt=0;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first<b.first){
        return true;
    }
    else if(a.first>b.second){
        return false;
    }
    else{
        return (a.second<b.second);
    }
}

void aro_govire_jao(vector<ll> g[],ll v){


    vis[v]=true;
    cnt++;
    //cout<<v<<endl;

    for(ll baccha:g[v]){

        if(vis[baccha]){
            continue;
        }

        aro_govire_jao(g,baccha);
        

        

    }
}


void caes(){
    ll n,m;
    cin>>n>>m;
    vector<ll> g[N];
    while(m--){
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    vector<pair<int,int>> ans(n+1);
    for(int i=0;i<n;i++){
        cnt=0;
        aro_govire_jao(g,i);
        ans[i].first=cnt;
        ans[i].second=i;
        for(int j=0;j<n;j++){
            vis[j]=false;
        }
    }
    sort(ans.begin(),ans.begin()+n);
    int k=1;
    for(int i=0;i<n-1;i++){
        cout<<k<<" "<<ans[i].second<<endl;
        if(ans[i].first!=ans[i+1].first){
            k++;
        }
    }
    cout<<k<<" "<<ans[n-1].second<<endl;
    //memset(vis,false,sizeof vis);

}
void somadhan(){
    ll t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Scenario #"<<i<<":\n";
        caes();
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}