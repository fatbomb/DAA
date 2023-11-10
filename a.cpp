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
int cnt=0;
bool fl=false;
bool ar[N];
vector<int> s;

void caes(){
    
    int n;
    cin>>n;
    vector<ll> v(n);
    for(auto &a:v){
        cin>>a;
    }
    vector<int> an(N,0);
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<s.size();j++){
            int k=0;
            while(v[i]%s[j]==0){
                v[i]/=s[j];
                k++;
                
            }
            if(k>an[s[j]]){
                ans-=an[s[j]];
                ans+=k;
                an[s[j]]=k;
            }
            
            
            if(v[i]==1)
                break;
            
        }
        
    }
    int x=0;
    if(ans&1){
        cout<<"Alice\n";
    }
    else{
        cout<<"Bob\n";
    }


}
void somadhan(){
    ll t=1;
    cin>>t;
    s.push_back(2);
    for(int i=3;i<N;i+=2){
        if(!ar[i]){
            s.push_back(i);
            for(int j=i+i;j<N;j+=i){
                ar[j]=true;
            }
        }
    }
    for(int i=0;i<t;i++){
        //cout<<"Case "<<i+1<<": ";
        caes();
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}