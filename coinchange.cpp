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
vector<int> Amount(10005,-1);
int func(int amount, vector<int> &coins){
    if(amount==0){
        return 0;
    }
    if(Amount[amount]!=-1){
        return Amount[amount];
    }
    int ans=INT_MAX;
    for(auto x:coins){
        
        if(amount-x>=0){
            int r=func(amount-x,coins);
            if(r!=-1){
                ans=min(ans,r+1);
            }
            
        }
    }
    if(ans==INT_MAX){
        ans=-1;
    }
    return Amount[amount]=ans;
    

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
    cout<<func(amount,v)<<endl;
    
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