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
        vll a,b;
        f(i,n){
            if(s[i]=='a') a.push_back(i);
            else b.push_back(i);
        }
        lli s1=a.size(),s2=b.size();
        lli median1,median2;
        if(s1!=0) median1=a[s1/2];
        if(s2!=0) median2=b[s2/2];
        lli ans1=0,ans2=0;
        if(s1!=0){
            lli mid1=s1/2;
            f(i,s1){
                ans1+=abs(a[i]-(median1+(i-mid1)));
            }
        }
        if(s2!=0){
            lli mid2=s2/2;
            f(i,s2){
                ans2+=abs(b[i]-(median2+(i-mid2)));
            }
        }
        cout<<min(ans1,ans2)<<"\n";
    }
    return 0;
}