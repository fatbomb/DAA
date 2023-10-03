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
vector<vector<int>> Amount(302,vector<int>(10005,-1));
int func(int amount, vector<int> &coins,int n){
    if(amount==0){
        return 1;
    }
    if(n<0){
        return  0;
    }
    if(Amount[n][amount]!=-1){
        return Amount[n][amount];
    }
    int ans=0;
    for(int i=0;i<=amount;i+=coins[n]){
        
        
            int r=func(amount-i,coins,n-1);
            //cout<<amount-x<<" "<<r<<endl;
            ans+=r;
            
    }
    //cout<<amount<<" "<<ans<<endl;
    
    return Amount[n][amount]=ans;
    

}
void caes(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int amount;
    cin>>amount;
    cout<<func(amount,v,n-1)<<endl;
    
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