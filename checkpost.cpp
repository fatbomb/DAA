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
// vector<ll> g[N];
bool vis[N];
ll d[N], h[N];
stack<int> s;
void aro_govire_jao(vector<ll> g[], ll v)
{

    vis[v] = true;

    for (ll baccha : g[v])
    {

        if (vis[baccha])
        {
            continue;
        }

        aro_govire_jao(g, baccha);
    }
    s.push(v);
}
void dfs(vector<ll> g2[], ll v)
{
    //cout<<v<<"\n";
    vis[v] = true;
    for (ll child : g2[v])
    {
        //cout<<child<<" ";
        if (vis[child])
        {
            continue;
        }
        
        dfs(g2, child);
    }
}

void caes()
{
    ll n;
    cin >> n;
    ll ar[n + 1];
    // for (int i=1;i<=n;i++){
    //     cin>>ar[i];
    // }
    vector<ll> g[n + 3], g2[n + 3];
    ll m;
    cin >> m;

    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g2[v].push_back(u);
        //cout<<u<<v;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            aro_govire_jao(g, i);
        }
    }
    memset(vis, false, sizeof vis);
    int i=1;
    //ll ans = 1, k = 0, mod = 1e9 + 7;
    dfs(g2,s.top());
    int x=s.top();
    s.pop();
    bool l=true;
    vector<pair<int,int>> v;
    while (!s.empty())
    {
        //cout<<s.top()<<endl;
        if (!vis[s.top()])
        {
            l=false;
            v.push_back({s.top(),x});
            dfs(g2, s.top());
            x=s.top();
            
            //cout << k << endl;
        }
        s.pop();
    }
    if(!l){
        cout<<"NO\n";
        for(pair<int,int> p:v){
            cout<<p.first<<" "<<p.second<<endl;
        }
    }
    else{
        cout<<"YES\n";
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