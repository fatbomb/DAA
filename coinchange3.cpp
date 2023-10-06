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

ll const N=1e7+1,mod=1000000007;
void multiply(ll f[2][2],ll m[2][2]){
    int w = (((f[0][0]*m[0][0])%mod + (f[0][1]*m[1][0]))%mod)%mod;
    int x = (((f[0][0]*m[0][1])%mod + (f[0][1]*m[1][1]))%mod)%mod;
    int y = (((f[1][0]*m[0][0])%mod + (f[1][1]*m[1][0]))%mod)%mod;
    int z = (((f[1][0]*m[0][1])%mod + (f[1][1]*m[1][1]))%mod)%mod; 
    f[0][0]=w,f[0][1]=x,f[1][0]=y,f[1][1]=z;

}
void power(ll f[2][2],ll n){
    if(n==0 or n==1){
        return;
    }
    ll m[2][2]={{1,1},{1,0}};
    power(f,n/2);
    multiply(f,f);
    if(n&1){
        multiply(f,m);
    }
}
ll mat(ll n){
    if(n==0){
        return 0;
    }
    ll f[2][2]={{1,1},{1,0}};
    power(f,n-1);
    return (f[0][0])%mod;
}
void caes(){
    ll n;
    cin>>n;
    cout<<mat(n)<<endl;

    
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