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

int cnt=0;
void merger(int s,int m,int f,vector<int> &v){
    vector<int> temp;
    int i=s;
    int j=m+1;
    while(i<=m and j<=f){
        if (v[i]<=v[j]){
            temp.push_back(v[i]);
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
            cnt+=m+1-i;
        }

    }
    while(i<=m){
        temp.push_back(v[i]);
        i++;

    }
    while(j<=f){
        temp.push_back(v[j]);
        j++;
    }
    for(int i=0;i<temp.size();i++){
        v[i+s]=temp[i];
    }




}
void mergersort(int i,int j,vector<int>&v){
    if(i<j){
        int m=(i+j)/2;
        mergersort(i,m,v);
        mergersort(m+1,j,v);
        merger(i,m,j,v);

    }
}
void caes(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &a:v){
        cin>>a;
    }
    mergersort(0,n-1,v);
    for(auto a:v){
        cout<<a<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;

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