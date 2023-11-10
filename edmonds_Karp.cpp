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

ll const n = 1e3 + 7;
ll const INF = 1e9 + 7;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll edmondsKarp(ll s, ll t, vector<ll> &par)
{
    fill(par.begin(), par.end(), -1);
    par[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});
    while (!q.empty())
    {
        ll c = q.front().first;
        ll f = q.front().second;
        q.pop();
        for (ll n : adj[c])
        {
            if (par[n] == -1 && capacity[c][n])
            {
                par[n] = c;
                int new_flow = min(f, capacity[c][n]);
                if (n == t)
                    return new_flow;
                q.push({n, new_flow});
            }
        }
    }
    return 0;
}
ll maxFlow(ll s, ll t)
{
    ll f = 0;
    vector<ll> par(n);
    ll nF;
    while ((nF = edmondsKarp(s, t, par)) > 0)
    {
        f += nF;
        ll c=t;
        while (c!=s)
        {
            ll p = par[c];
            capacity[p][c] -= nF;
            capacity[c][p] += nF;
            c = p;
            
        }
        
    }
    return f;
}
void caes()
{
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