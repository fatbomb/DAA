#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endl "\n"

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

ll const N = 1e4 + 7;
vector<int> g[N];
vector<pair<int, pair<int, int>>> tim(N);
void make_graph(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
bool vis[N];
int m = 1;
void dfs(ll v, int k)
{
    tim[v].first = k;
    tim[v].second.first = m;
    m++;

    vis[v] = true;

    for (ll ch : g[v])
    {
        if (vis[ch])
        {
            continue;
        }

        dfs(ch, k);
    }
    tim[v].second.second = m;
    m++;
}
void caes()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        make_graph(u, v);
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, k);
            k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": " << tim[i].first << " " << tim[i].second.first << " " << tim[i].second.second << endl;
    }
}
void solve()
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
    fio
    solve();
    return 0;
}