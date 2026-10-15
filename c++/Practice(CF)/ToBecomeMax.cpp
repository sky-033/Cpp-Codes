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

bool check(vll &a,vll &maxia,lli n,lli mid,lli k){
    f(i,n){
        if(maxia[i]<mid) continue;
        // else if(mid-a[i]<=k) return true;
        lli ct=0;
        // if(ct>k) continue;
        bool flag=true;
        for(lli j=i;j<n-1;j++){
            lli need=mid-(j-i);
            if(need<=a[j]) break;
            if(maxia[j]<need){
                flag=false;
                break;
            }
            ct+=max(0LL,need-a[j]);
            if(ct>k){
                flag=false;
                break;
            }
        }
        if(flag) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n),maxia(n);
        f(i,n) cin>>a[i];
        lli maxi=a[n-1];
        maxia[n-1]=maxi;
        for(lli i=n-2;i>=0;i--){
            if(a[i]>maxi){
                maxia[i]=a[i];
                maxi=a[i];
            }
            else{
                maxia[i]=maxi+1;
                maxi++;
            }
        }
        lli l=0,h=*max_element(all(a))+k,mid;
        while(h-l>1){
            mid=(l+h)>>1;
            if(check(a,maxia,n,mid,k)) l=mid;
            else h=mid-1;
        }
        if(check(a,maxia,n,h,k)) cout<<h<<"\n";
        else cout<<l<<"\n";
    }
    return 0;
}