// Proud to be a Bangali :)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define endl "\n"

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define arektu_row_na_somoy           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll const N = 2e5 + 7;
int findMed(vector<int> &v)
{
    return 100;
}
int partition(vector<int> &v, int s, int f)
{
    int x= v[f],i=s-1;
    for(int j=s;j<f;j++){
        if (x >= v[j]) {
            i++;
            swap(v[i],v[j]);
        }
        // for(int k=s;k<=f;k++){
        //     cout<<v[k]<<" ";
        // }
        // cout<<endl;

    }
    swap(v[i+1],v[f]);
    return i+1;
}
int medianOfMedians(int k, vector<int> &v, int l, int r)
{
    if(k<1 or l>r){
        
        return -1;
    }
    //int p= findMed(v);
    
    int p=partition(v,l,r);
    //cout<<p<<endl;
    if(k-1==p){
        return v[p];
    }
    else if(k-1<p){
        return medianOfMedians(k,v,l,p-1);
        
    }
    else{
        return medianOfMedians(k,v,p+1,r);
    }
}

void caes()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &a : v)
    {
        cin >> a;
    }
    //medianOfMedians(k, v, 0, n - 1);
    cout << medianOfMedians(k, v, 0, n - 1) << endl;
}
void somadhan()
{
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        caes();
    }
}
int main()
{
    arektu_row_na_somoy
    somadhan();
    return 0;
}