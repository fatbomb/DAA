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


void caes(){
    int n;
    cin>>n;
    vector<ll> v(n);
    vector<vector<ll>> dp(n,vector<ll> (n,INT_MAX));
    for(int i=0;i<n;i++){
        cin>>v[i];
        dp[i][i]=0;
    }
    for(int i=n-1;i>0;i--){
        for(int j=i+1;j<n;j++){
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],v[i-1]*v[j]*v[k]+dp[i][k]+dp[k+1][j]);
            }
        }
        cout<<endl;
    }
    cout<<dp[1][n-1]<<endl;
    
    
    
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