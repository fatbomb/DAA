#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back

vector<vector<int>> adj;
const int M = 1001;
int indegree[M];
vector<vector<int>> r;

#define debug(x) cerr << __LINE__ << " " << (#x) << ' ' << x << endl;

void top_sort(int V) {
    r.clear();
    r.resize(V + 1); 

    queue<int> q;
    for (size_t i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            r[1].pb(i);
        }
    }

    int curr_rank = 2;

    while (!q.empty()) {
        int u = q.front();
        debug(u);
        q.pop();
        bool x=false;
        for (auto it : adj[u]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                debug(curr_rank);
                q.push(it);
                r[curr_rank].pb(it);
                x=true;
            }
        }
        if(x){
            curr_rank++;
        }
       
    }
    cout<<curr_rank<<"\n";

    for (size_t i = 1; i <curr_rank; i++) { 
        for (auto it : r[i]) {
            cout << i << " " << it << "\n";
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (size_t i = 1; i <= t; i++) {
        int V, E;
        cin >> V >> E;
        adj.clear();
        adj.resize(V); 

        fill(indegree, indegree + V, 0); 

        for (size_t i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[v].pb(u);
            indegree[u]++;
        }

        cout << "Scenario #" << i << ":\n"; 
        top_sort(V);
    }
}