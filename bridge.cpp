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
vector<ll> g[N];
bool vis[N];
ll tim[N], low[N];
int timer = 1;
void aro_govire_jao(ll v, int parent, vector<pair<int,int>> &bridge)
{
    tim[v] = low[v] = timer;
    timer++;
    vis[v] = true;

    for (ll baccha : g[v])
    {

        if (baccha == parent)
            continue;

        if (!vis[baccha])
        {

            aro_govire_jao(baccha,v,bridge);
            low[v] = min(low[v], low[baccha]);
            if(low[baccha]>=tim[v]){
                bridge.push_back({v,baccha});
            }
        }
        else{
            low[v]=min(low[v],tim[baccha]);
        }
    }
}

void caes()
{
    /*code*/
    int n, m;
    cin >> n, m;
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    vector<pair<int, int>> bridges;
    aro_govire_jao(0,-1,bridges);
    for(auto br: bridges){
        cout<<br.first<<" "<<br.second<<endl;
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