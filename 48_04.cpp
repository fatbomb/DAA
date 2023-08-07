
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
#define endl "\n" 


#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const N=2e5+7;
vector<int> g[N];
int vis[N];
ll d[N],h[N];
bool hascycle =false;
void dfs(ll v,int par){

    vis[v]=1;

    for(ll ch:g[v]){

        if(vis[ch]==2 or ch==par){
            continue;
        }
        else if(vis[ch]==1){
            hascycle=true;
            //cout<<v<<endl;
            return;
        }

        dfs(ch,v);


    }
    vis[v]=2;
}

void make_graph(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}

void caes(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        make_graph(u,v);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    if(hascycle){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}
void solve(){
    ll t=1;
    //cin>>t;
    while(t--){
        caes();
    }
}
int main(){
    fio
    solve();
    return 0;
}