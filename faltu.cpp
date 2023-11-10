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


void caes(){
    string pattern,s;
    cin>>pattern;
    getline (cin , s) ;
    vector<string> v(26,"");
    cout<<pattern<<endl;
    cout<<s<<endl;
        
        // int j=0;
        // for(int i=0;i<pattern.size();i++){
        //     string t="";
        //     while(s[j]!=' '){
        //         t+=s[j];
        //         j++;
        //     }
        //     cout<<t<<endl;
        //     // if(v[pattern[i]-'a']==""){
        //     //     v[pattern[i]-'a']=t;
        //     // }
        //     // else{
        //     //     if(v[pattern[i]-'a']!=t){
        //     //         cout<<t<<" "<<v[pattern[i]-'a']<<endl;
        //     //         return;
        //     //         // return false;
        //     //     }
        //     // }
        //     // t="";
        //     j++;
        // }
        // if(j<s.size()){
        //     cout<<1<<endl;
        //     return;
        //     //return false;
        // }
        cout<<-1<<endl;
        
        //return true;   
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