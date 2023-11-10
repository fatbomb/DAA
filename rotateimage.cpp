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

void caes()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    for(auto &a:matrix){
        for(auto &b:a){
            cin>>b;
        }
    }
    //int n=matrix.size();
        //int m=matrix[0].size();
        vector<int> v(n*m+1);
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                v[k]=matrix[i][j];
                cout<<v[k]<<" "<<k<<endl;
                k++;

            }
            if(k>=(n*m)){
                break;
            }
            for(int j=i+1;j<n;j++){
                v[k]=matrix[j][m-1];
                cout<<v[k]<<" "<<k<<endl;
                k++;
            }
            if(k>=(n*m)){
                break;
            }
            for(int j=m-2;j>=i;j--){
                v[k]=matrix[n-1][j];
                cout<<v[k]<<" "<<k<<endl;
                k++;
            }
            if(k>=(n*m)){
                break;
            }
            for(int j=n-2;j>i;j--){
                v[k]=matrix[j][i];
                cout<<v[k]<<" "<<k<<endl;
                k++;
            }
            if(k>=(n*m)){
                break;
            }
            n--;
            m--;

        }
        v.pop_back();
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