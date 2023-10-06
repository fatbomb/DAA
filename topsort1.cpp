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
int vis[N];
ll d[N],h[N];
stack<int> s;
bool fl=false;


void caes(){
    /*code*/
    int n,m;
    cin>>n>>m;
    vector<int> ind(n+1,0),order;
    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        ind[b]++;
    }
    set<int> s;

    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            s.insert(i);
        }
    }
    int cnt=0;
    while(!s.empty()){
        int u=*s.begin();
        s.erase(s.begin());
        order.push_back(u);
        for(auto x:g[u]){
            if(--ind[x]==0){
                s.insert(x);
            }
        }
        cnt++;
    }
    if(cnt!=n){
        cout<<-1<<endl;
        return;
    }
    for(auto x:order){
        cout<<x<<" ";
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