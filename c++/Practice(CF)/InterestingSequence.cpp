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
        lli n,x;
        cin>>n>>x;
        bool flag=true;
        lli ans=-1;
        // if(bitlen(n)!=bitlen(x)) flag=false;
        // else{
            if((n&x)!=x) flag=false;
            else{
                lli ct=0;
                f(i,62){
                    if((n&(1LL<<i)) && ((x&(1LL<<i)))){
                        ct=1;
                    }
                    else if((n&(1LL<<i)) && ((x&(1LL<<i))==0)){
                        if(ct==1){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag){
                    lli first=-1;
                    f(i,62){
                        if((n&(1LL<<i)) && ((x&(1LL<<i)))){
                            first=i;
                            break;
                        }
                    }
                    if(first>0){
                        first--;
                        if(n&(1LL<<first)) flag=false;
                    }
                }
                if(flag){
                    lli num=n^x; 
                    lli len=bitlen(num);
                    lli extra=(1LL<<len)-num;
                    ans=n+extra;
                    if(num==0) ans=n;
                }
            }
        
        cout<<ans<<"\n";
    }
    return 0;
}