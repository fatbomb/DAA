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
    vector<int> g(n + 1, vector<int>(n + 1));
    vector<int> deg(n + 1);
    for (auto i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
        ++deg[a], ++deg[b];
    }
    int first = 0;
    while (first < n and !deg[first])
    {
        ++first;
    }
    if (first == n)
    {
        cout << "-1" << endl;
        return;
    }
    int v1 = -1, v2 = -1;
    bool bad = false;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] & 1)
        {
            if (v1 == -1)
            {
                v1 = i;
            }
            else if (v2 == -1)
            {
                v2 = i;
            }
            else
            {
                bad = true;
            }
        }
    }
    if (v1 != -1)
    {
        ++g[v1][v2].++g[v2][v1];
    }
    stack<int> st;
    st.push(first);
    vector<int> res;
    while (!st.empty())
    {
        int v = st.top();
        int i;
        for (i = 0; i < n; ++i)
        {
            if (g[v][i])
            {
                break;
            }
        }
        if (i == n)
        {
            res.push_back(v);
            st.pop();
        }
        else
        {
            --g[v][i];
            --g[i][v];
            st.push(i);
        }
    }
    if (v1 != -1)
    {
        for (size_t i = 0; i + 1 < res.size(); ++i)
        {
            if ((res[i] == v1 && res[i + 1] == v2) ||
                (res[i] == v2 && res[i + 1] == v1))
            {
                vector<int> res2;
                for (size_t j = i + 1; j < res.size(); ++j)
                    res2.push_back(res[j]);
                for (size_t j = 1; j <= i; ++j)
                    res2.push_back(res[j]);
                res = res2;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j])
                bad = true;
        }
    }

    if (bad)
    {
        cout << -1;
    }
    else
    {
        for (int x : res)
            cout << x << " ";
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