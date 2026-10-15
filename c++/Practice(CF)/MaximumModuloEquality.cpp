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

void build(lli node,lli st,lli en,vll &diff,vll &seg ){
    if(st==en){
        seg[node]=diff[st];
        return;
    }
    lli mid=(st+en)/2;
    build(2*node+1,st,mid,diff,seg);
    build(2*node+2,mid+1,en,diff,seg);
    seg[node]=__gcd(seg[2*node+1],seg[2*node+2]);
}

lli query(lli node,lli st,lli en,lli l,lli r,vll &seg){
    if(r<st || en<l) return 0;
    if(l<=st && r>=en) return seg[node];
    lli mid=(en+st)/2;
    lli left=query(2*node+1,st,mid,l,r,seg);
    lli right=query(2*node+2,mid+1,en,l,r,seg);
    return __gcd(left,right);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,q;
        cin>>n>>q;
        vll a(n),diff;
        f(i,n) cin>>a[i];
        f(i,n-1) diff.push_back(abs(a[i+1]-a[i]));
        vll seg(4*(n-1));
        if(n==1){
            while(q--){
                lli l,r;
                cin>>l>>r;
                cout<<0<<" ";
            }
            cout<<"\n";
            continue;
        }
        build(0,0,n-2,diff,seg);
        while(q--){
            lli l,r;
            cin>>l>>r;
            if(l==r) cout<<0<<" ";
            else{
                cout<<query(0,0,n-2,l-1,r-2,seg)<<" ";
            }  
        }
        cout<<"\n";
    }
    return 0;
}