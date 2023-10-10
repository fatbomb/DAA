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
ll mcmtopdown(int i, int j, vector<ll> &v,vector<vector<ll>> &dp){
    if (i==j) return 0LL;
    else if(dp[i-1][j-2]!=-1){
        return dp[i-1][j-2];
    }
    else{
        ll mi=INT_MAX;
        for(int k=i;k<j;k++){
            mi=min(mcmtopdown(i,k,v,dp)+mcmtopdown(k+1,j,v,dp)+(v[i-1]*v[j]*v[k]),mi);
        }
        return dp[i-1][j-2]=mi;
    }


}

void caes(){
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<vector<ll>> dp(n-2,vector<ll> (n-2,-1));
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    cout<<mcmtopdown(1, n-1, v,dp)<<endl;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }



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