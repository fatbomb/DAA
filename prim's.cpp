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
int spanningTree(int V, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V + 1, 0);

    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty())
    {
        pair<int, int> it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (!vis[node])
        {
            vis[node] = 1;
            sum += wt;
            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int weight = x.second;
                if (!vis[adjNode])
                {
                    pq.push({weight, adjNode});
                }
            }
        }
    }
    return sum;
}

void caes()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(make_pair(b, c));
        g[b].emplace_back(make_pair(a, c));
    }
    int sum = spanningTree(n, g);
    cout << sum << endl;
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