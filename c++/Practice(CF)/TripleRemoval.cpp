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
        lli n,q;
        cin>>n>>q;
        vll a(n);
        f(i,n) cin>>a[i];
        vll prefix(n,0);
        prefix[0]=a[0];
        ff(1,n,1) prefix[i]=prefix[i-1]+a[i];
        set<lli> store;
        f(i,n-1){
            if(a[i]==a[i+1]) {
                store.insert(i+1);
                store.insert(i+2);
            }
        }
        while(q--){
            lli l,r;
            cin>>l>>r;
            if((r-l+1)%3!=0) cout<<-1<<"\n";
            else{
                if(l==1){
                    if(prefix[r-1]%3!=0) cout<<-1<<"\n";
                    else{
                        lli val=*store.upper_bound(l);
                        if(val<r && val>l){
                            cout<<(r-l+1)/3<<"\n";
                        }
                        else cout<<(r-l+1)/3+1<<"\n";
                    }
                }
                else{
                    if((prefix[r-1]-prefix[l-2])%3!=0) cout<<-1<<"\n";
                    else{
                        lli val=*store.upper_bound(l);
                        if(val<r && val>l){
                            cout<<(r-l+1)/3<<"\n";
                        }
                        else cout<<(r-l+1)/3+1<<"\n";
                    }
                }
            }
        }
    }
    return 0;
}