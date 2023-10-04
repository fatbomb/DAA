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

void printlcs(vector<vector<int>> &p,string s2,int i, int j){
    if(i==0 or j==0){
        return;
    }
    //cout<<i<<" "<<j<<" "<<p[i][j]<<"\n";
    if(p[i][j]==1){
        printlcs(p,s2,i-1,j-1);
        cout<<s2[i-1];
    }
    else if(p[i][j]==-1){
        printlcs(p,s2,i-1,j);
    }
    else{
        printlcs(p,s2,i,j-1);
    }
}
void caes(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0)),p(s1.size()+1,vector<int>(s2.size()+1,0));
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1]=dp[i][j]+1;
                p[i+1][j+1]=1;
            }
            else{
                dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                if(dp[i][j+1]>dp[i+1][j]){
                    p[i+1][j+1]=-1;
                }
                else{
                    p[i+1][j+1]=0;
                }
            }
        }
    }
    
    cout<<dp[s1.size()][s2.size()]<<endl;
    printlcs(p,s1,s1.size(),s2.size());
    

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