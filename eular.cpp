//Proud to be a Bangali :)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
#define endl "\n" 

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define arektu_row_na_somoy ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const N=2e5+7;
vector<int> g[N];
// unordered_map<int,vector<int>> adj;
// void DFS(int curr,vector<bool>& visited)
// {
// 	visited[curr]=true;
// 	for(auto it: adj[curr])
// 	{
// 		if(!visited[it])
// 			DFS(it,visited);
// 	}
// }
// bool Connected_Graph()
// {
// 	vector<bool> visited(V+1,false);
// 	int node = -1;	//Node to start DFS
// 	for(int i=0;i<V;++i)
// 		if(adj[i].size()>0)
// 		{
// 			node = i;	//Found a node to start DFS
// 			break;
// 		}
// 	if(node == -1)	//No start node was found-->No edges are present in graph
// 		return true; //It's always Eulerian

// 	DFS(node,visited);
// 	//Check if all the non-zero vertices are visited
// 	for(int i=0;i<V;++i)
// 		if(visited[i]==false and adj[i].size()>0)
// 			return false;	//We have edges in multi-component
// 	return true;
// }

// int findEuler()
// {
// 	if(!Connected_Graph())	//multi-component edged graph
// 		return 0;		//All non-zero degree vertices should be connected

// 	//Count odd-degree vertices
// 	int odd = 0;
// 	for(int i=0;i<V;++i)
// 		if(adj[i].size() & 1)
// 			odd += 1;

// 	if(odd > 2)	//Only start and end node can have odd degree
// 		return 0;

// 	return (odd==0)?2:1;	//1->Semi-Eulerian...2->Eulerian
// }
// void findEulerPathCycle(){
//     int ret=findEuler();
//     if (ret==0) cout<<"No Euler Path"<<endl;
//     else if(ret==1){
//         cout<<"Graph is a semiEulerian\n";
//     }
//     else{
//         cout<<"Graph is Euleriab (Euler circuit)\n";
//     }
// }
void find_path(int start, vector<vector<int> >& adj,vector<int>& ans) {

    while(!adj[start].empty()) {
        int v = adj[start].back();
        adj[start].pop_back();
        auto it = find(adj[v].begin(),adj[v].end(),start);
        adj[v].erase(it);
                
        find_path(v,adj,ans);

    }
    ans.push_back(start);
}
void caes(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g2(n+1);
    vector<int> deg(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        g2[a].push_back(b);
        g2[b].push_back(a);
        deg[a]++;
        deg[b]++;


    }
    vector<int> ans;
    int a=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(deg[i]&1){
            cnt++;
            a=i;
        }
    }
    if(a==-1){
        a=0;
    }
    if(cnt>2){
        cout<<"No Euler path present.\n";
    }
    find_path(a,g2,ans);
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
}
void somadhan(){
    ll t=1;
    //cin>>t;
    while(t--){
        caes();
    }
}
int main(){
    arektu_row_na_somoy
    somadhan();
    return 0;
}