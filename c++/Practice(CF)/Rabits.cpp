#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
// template <typename T>using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag tree_order_statistics_node_update>;
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vll store;
        vll used(n,0);
        bool ans=true;
        ff(1,n-1,1){
            if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1'){
                used[i]=1;
            }
        }
        ff(1,n-1,1){
            if(s[i]=='0' && s[i-1]=='1' && s[i+1]=='1'){
                bool check=false;
                lli a1=i-2,a2=i+2;
                if(a1>=0 && used[a1]==0 && s[a1]=='0' ){
                    used[i]=0;
                    check=true;
                }
                else if(a2<n && used[a2]==0 && s[a2]=='0'){
                    used[i]=0;
                    check=true;
                }
                else if(a1>=0 && s[a1]=='0' ){
                    s[i]=s[a1]='1';
                    check=true;
                }
                else if(a2<n && s[a2]=='0'){
                    s[i]=s[a2]='1';
                    check=true;
                }
                if(!check){
                    ans=false;
                    break;
                }
            }
        }
        if(ans) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}