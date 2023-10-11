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
int dist(pair<int,int> a ,pair<int,int> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}
int naive(vector<pair<int,int>> &v, int n){
    int mi=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mi=min(mi,dist(v[i],v[j]));
        }
    }
    return mi;
}
bool comparey(pair<int,int> a ,pair<int,int> b ){
    return a.second<b.second;
}

int clstrip(vector<pair<int,int>> &strip,int s,int d){
    int m=d;
    sort(strip.begin(),strip.end(),comparey);
    for(int i=0;i<s;i++){
        for(int j=i+1 ;j<s and strip[j].second-strip[i].second<m;j++){
            m=min(m,dist(strip[i],strip[j]));
        }
    }
    return m;

}

int closestpoint(vector<pair<int,int>> &v, int n,int st){
    if(n<=3){
        return naive(v,n);
    }
    int m=n/2;
    m+=st;
    pair<int,int> mid=v[m];

    int distl = closestpoint(v,m,st);
    int distr = closestpoint(v,n-m,m);

    int dist=min(distl,distr);

    vector<pair<int,int>> strip(n);
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(v[i].first-mid.first)<dist){
            strip[j]=v[i];
            j++;
        }
    }

    return min(dist,clstrip(strip,j,dist));
}


void caes(){
    /*code*/
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(auto &a:v){
        cin>>a.first>>a.second;
    }
    sort(v.begin(),v.end());
    cout<<sqrt(closestpoint(v,n,0))<<endl;

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