
#include<bits/stdc++.h>


using namespace std;

typedef long long ll;
#define endl "\n" 


#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const N=1e5+7;
vector<int> g[N];
void make_graph(int u, int v){
    g[u].push_back(v);
}


void caes(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        make_graph(u,v);
    }
    vector<int> v(n,-1);
    vector<bool> vis(n,false);
    queue<int> q;
    v[0]=0;
    q.push(0);
    vis[0]=true;
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(int f:g[x]){
            if(!vis[f]){
                q.push(f);
                vis[f]=true;
                v[f]=v[x]+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        if(v[i]==-1){
            cout<<"Not Reachable\n";
        }
        else{
            cout<<v[i]<<"\n";
        }
    }


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