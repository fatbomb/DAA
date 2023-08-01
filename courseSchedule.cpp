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

ll const N = 1e3 + 7;
vector<ll> g[N];
bool vis[N];
ll d[N], h[N];
void aro_govire_jao(vector<ll> g[], ll v, stack<int> &s)
{

    vis[v] = true;

    for (ll baccha : g[v])
    {

        if (vis[baccha])
        {
            continue;
        }

        aro_govire_jao(g,baccha,s);
    }
    s.push(v);
}

void caes(int n, int m)
{
    memset(vis, false, sizeof vis);
    vector<ll> g[n + 3];
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    stack<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            aro_govire_jao(g, i,s);
   }
   while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
   }
   cout<<endl;
}
void somadhan()
{
    ll t = 1;
    // cin>>t;
    while (1)
    {
        ll n, m;
        cin >> n >> m;
        if (n == m and m == 0)
        {
            break;
        }
        caes(n, m);
    }
}
int main()
{
    arektu_row_na_somoy
    somadhan();
    return 0;
}