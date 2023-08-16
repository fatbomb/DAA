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

ll const N = 1e5 + 7;
const ll INF = 1e9 + 7;

vector<pair<int, int>> g[N];

void dijkstra(int source)
{
    vector<ll> dist(N, INF);
    vector<bool> vis(N, false);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto child : g[u])
        {
            ll v = child.first;
            ll wt = child.second;
            if (dist[u] + wt < dist[v])
            {
                dist[v] = dist[v] + wt;
                pq.push({dist[v], v});
            }
        }
    }
}

void caes()
{
    ll n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
    }
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