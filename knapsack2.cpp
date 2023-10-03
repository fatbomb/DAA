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
vector<vector<ll>> Amount(102, vector<ll>(100005, -1));
ll func(ll amount, vector<pair<ll, ll>> &we, ll n)
{
    if(n<0){
        return 0;
    }
    if (amount <= 0)
    {
        return 0;
    }
    if (Amount[n][amount] != -1)
    {
        return Amount[n][amount];
    }
    ll ans = 0;
    ans=func(amount,we,n-1);
    if(amount-we[n].first>=0){
        ans=max(ans,func(amount-we[n].first,we,n-1)+we[n].second);    }
    
    
    // cout<<amount<<" "<<ans<<endl;

    return Amount[n][amount] = ans;
}
void caes()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> v(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
            
    //         if (v[i].first <= j)
    //             Amount[i][j] = max(v[i].second + Amount[i-1][j - v[i].first], Amount[i-1][j]);

    //         else{
    //             Amount[i][j]=Amount[i-1][j];
    //         }
    //     }
    // }
    // cout<<Amount[n][m]<<endl;
    cout<<func(m,v,n-1)<<endl;
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