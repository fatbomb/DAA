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
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &a:nums){
        cin>>a;
    }
    string p;
    if(n==0){
        cout<<0<<endl;
        return;
    }
    unordered_set<int> s;
    for(int a:nums){
        s.insert(a);
    }
    int ans=1;
    for(int a:s){
        if(s.find(a-1)==s.end()){
            int cnt=1;
            while(s.find(a+1)!=s.end()){
                a++;
                cnt++;

            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    // return true;
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