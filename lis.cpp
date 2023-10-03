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

int func1(int n, vector<ll> &v, vector<ll> &dp, vector<vector<int>> &z)
{
    if (n == 0)
    {
        if (dp[0] == 0)
        {
            z[0].push_back(v[0]);
            dp[0] = 1;
        }

        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = 1;
    int x = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] < v[n])
        {
            int nn = func1(i, v, dp, z);
            if (nn + 1 > dp[n])
            {
                dp[n] = nn + 1;
                x = i;
            }
        }
    }
    if (x != -1)
        for (auto nn : z[x])
        {
            z[n].push_back(nn);
        }
    z[n].push_back(v[n]);
    return dp[n];
}
int func2(vector<ll> &v)
{
    vector<ll> dp;
    for (int i = 0; i < v.size(); i++)
    {
        ll x = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if (x == dp.size())
        {
            dp.push_back(v[i]);
        }
        else
        {
            dp[x] = v[i];
        }
    }
    return dp.size();
}

void caes()
{
    ll n;
    cin >> n;
    vector<ll> v(n), dp(n, -1);
    for (auto &x : v)
    {
        cin >> x;
    }
    int mx = 0;
    int r = -1;
    vector<vector<int>> z(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        int x = func1(i, v, dp,z);
        if (x > mx)
        {
            mx = x;
            r = i;
        }
    }
    cout << mx << endl;
    for (auto x : z[r])
    {
        cout << x << " ";
    }
    // cout<<func2(v)<<endl;
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