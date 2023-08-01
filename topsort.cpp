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
vector<ll> g[N];
bool vis[N];
ll d[N],h[N];
stack<int> s;
void aro_govire_jao(ll v){

    vis[v]=true;

    for(ll baccha:g[v]){

        if(vis[baccha]){
            continue;
        }

        aro_govire_jao(baccha);

    }
    s.push(v);

}

void caes(){
    /*code*/
    int n,m;
    cin>>n>>m;
    while(n--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            aro_govire_jao(i);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
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