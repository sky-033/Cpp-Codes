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
        vll prefix(n,0),suffix(n,0);
        if(s[0]=='0') prefix[0]=0;
        else prefix[0]=1;
        ff(1,n,1){
            if(s[i]=='1') prefix[i]=1+prefix[i-1];
            else prefix[i]=prefix[i-1];
        }
        lli mid=(n)/2;
        lli ans=1e9;
        for(lli i=mid;i>=0;i--){
            if(i==0){
                lli zeroes=0;
                lli ones=prefix[n-1];
                if(ones>=(n-i+1)/2 && zeroes>=(i+1)/2){
                    ans=i;
                    break;
                }
            }
            else{
                lli ones=prefix[n-1]-prefix[i-1];
                lli zeroes=i-prefix[i-1];
                if(ones>=(n-i+1)/2 && zeroes>=(i+1)/2){
                    ans=i;
                    break;
                }
            }
        }
        lli ans1=1e9;
        for(lli i=mid;i<=n;i++){
            lli zeroes=i-prefix[i-1];
            lli ones=prefix[n-1]-prefix[i-1];
            if(ones>=(n-i+1)/2 && zeroes>=(i+1)/2){
                ans1=i;
                break;
            }
        }
        // cout<<ans<<" "<<ans1<<endl;
        // cout<<min(n/2-ans,abs(n/2-ans1))<<"\n";
        if(ans!=1e9 && (n+1)/2-ans<=abs((n+1)/2-ans1)) cout<<ans<<"\n";
        else cout<<ans1<<"\n";
    }
    return 0;
}