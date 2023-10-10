#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<vi> adj;
vector<int> vis, topo;
bool cycle;
#define debug(x) cerr << (#x) << ' ' << x << endl;
#define ss second
#define ff first
#define pb push_back
const int MAX = 2e5 + 5;
int deg[MAX];



void topologicalSort(int V)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (size_t i = 1; i <= V; i++)
    {
        if (deg[i] == 0)
            pq.push(i);
    }

    vector<int> ans;
    

    while (!pq.empty())
    {

        int u = pq.top();
        pq.pop();
        if (!deg[u])
        {
            ans.pb(u);
            for (auto it : adj[u])
            {
                deg[it]--;
                if (deg[it] == 0)
                    pq.push(it);
            }
        }

        else
        {
            cout << "-1"
                 << "\n";
            exit(0);
        }
    }

    if (ans.size() != V){
        cout << "-1"<< "\n";
        return;
            
    }
            

    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}

int main()
{
    int V, E;
    cin >> V >> E;
    adj.resize(V + 1);

    for (size_t i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    topologicalSort(V);

    return 0;
}