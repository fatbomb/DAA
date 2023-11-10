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
    vector<string> op(n);
    for(auto &a:op){
        cin>>a;
    }
    vector<int> v(op.size());
        int j=0;
        int i=0;
        while(i<op.size()){
            if(op[i][0]=='C'){
                if(j!=0){
                    j--;
                    v[j]=0;
                }
            }
            else if(op[i][0]=='D'){
                if(j!=0){
                    v[j]=v[j-1]*2;
                    j++;
                }
            }
            else if(op[i][0]=='+'){
                if(j>1){
                    v[j]=v[j-1]+v[j-2];
                    j++;
                }
            }
            else{
                int k=1;
                int x=0;
                if(op[i][0]=='-'){
                    k=-1;
                    x++;
                    
                }
                int ans=0;
                while(x<op[i].size()){
                    ans=(ans*10)+op[i][x]-'0';
                    x++;
                }
                v[j]=ans*k;
                j++;




            }
            cout<<v[j-1]<<" ";
            i++;

        }
        int ans=0;
        cout<<i<<endl;
        for(int x=0;x<j;x++){
            ans+=v[x];
        }
        cout<<ans;
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