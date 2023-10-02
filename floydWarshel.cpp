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

ll const N=1e5+7;
ll const INF=1e9+10;

void printdistance(vector<vector<int>> &dist,int n){
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    cout<<"0 ";
                }
                else if(dist[i][j]==INF){
                    cout<<"INF ";
                }
                else{
                    cout<<dist[i][j]<<" ";
                } 

            }
            cout<<endl;
        }
}

void caes(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u-1][v-1]=w;
    }
    for(int k=0;k<n;++k){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INF and dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    cout<<"0  ";
                }
                else if(dist[i][j]==INF){
                    cout<<"Inf  ";
                }
                else{
                    cout<<dist[i][j]<<"  ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        

    }
    printdistance(dist,n);
    
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