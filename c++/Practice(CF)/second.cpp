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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        set<lli> indx;
        f(i,n){
            if(s[i]=='0') indx.insert(i+1);
        }
        bool flag=true;
        lli ct=0;
        f(i,n){
            if(s[i]=='1'){
                ct++;
                if(ct>=k){
                    flag=false;
                    break;
                }
            }
            else ct=0;
        }
        if(flag){
            cout<<"YES"<<endl;
            lli val=n,val1=1;
            vll ans(n,0);
            f(i,n){
                if(s[i]=='0'){
                    ans[i]=val;
                    val--;
                }
                else{
                    ans[i]=val1;
                    val1++;
                }
            }
            fa(ans) cout<<it<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}