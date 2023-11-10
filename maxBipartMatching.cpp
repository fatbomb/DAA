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
int n,k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
bool tryKuhn(int v){
    if(used[v]){
        return false;
    }
    used[v]=true;
    for (int t:g[v]){
        if(mt[t]==-1 or tryKuhn(mt[t])){
            mt[t]=v;
            return true;
        }
    }
    return false;

}
bool bpm(vector<vector<bool>> &bpGraph,int i, vector<bool>&seen, vector<int> &matchR,int m,int n){
    for(int v=0;v<n;v++){
        if(bpGraph[i][v] and !seen[v]){
            seen[v]=true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR,m,n))
            {
                matchR[v] = i;
                return true;
            }
        }
    }
    return false;
}
int maxBpm(vector<vector<bool>> &bpGraph,int m,int n){
    vector<int> matchR(n,-1);
    int res=0;
    for(int i=0;i<m;i++){
        vector<bool> seen(n,false);
        if(bpm(bpGraph,i,seen,matchR,m,n)){
            res++;
        }
    }
    return res;
}



void caes(){
    int n,m;
    cin>>m>>n;
    vector<vector<bool>> bpGraph(m,vector<bool>(n));
    cout<<maxBpm(bpGraph,m,n);
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