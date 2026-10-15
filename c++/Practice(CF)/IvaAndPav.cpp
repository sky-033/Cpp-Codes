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

lli calc(vvll &prefix,lli mid,lli l){
    lli num=0;
    lli len=mid-(l-1)+1;
    f(i,31){
        if(l==1){
            if(prefix[mid][i]==len) num|=(1LL<<i);
        }
        else{
            if(prefix[mid][i]-prefix[l-2][i]==len) num|=(1LL<<i);
        }
    }
    return num;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        vvll prefix(n,vll (31));
        f(i,n){
            f(j,31) prefix[i][j]=0;
        }
        lli num=a[0];
        f(i,31){
            if(num&(1LL<<i)) prefix[0][i]++;
        }
        for(lli i=1;i<n;i++){
            num=a[i];
            f(j,31){
                if(num&(1LL<<j)) prefix[i][j]=prefix[i-1][j]+1;
                else prefix[i][j]=prefix[i-1][j];
            }
        }
        lli q;
        cin>>q;
        while(q--){
            lli l,k;
            cin>>l>>k;
            if(a[l-1]<k){
                cout<<-1<<" ";
                continue;
            }
            lli low=l-1,high=n-1,mid;
            while(high-low>1){
                mid=(low+high)/2;
                lli num=calc(prefix,mid,l);
                if(num>=k) low=mid;
                else high=mid;
            }
            if(calc(prefix,high,l)>=k) cout<<high+1<<" ";
            else cout<<low+1<<" ";   
        }
        cout<<"\n";
    }
    return 0;
}