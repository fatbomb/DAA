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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)), dp(n + 1, vector<int>(m + 2));
    for (int j = 0; j < m + 2; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = INT_MAX;
        dp[i][m+1] = INT_MAX;
    }
    for (auto &x : v)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]})+v[i-1][j-1];
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<m+1;i++){
        ans=min(ans,dp[n][i]);
    }
    // for(int i=1;i<n+1;i++){
    //     for(int j=1;j<m+1;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<endl;
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