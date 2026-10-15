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

bool check(vll &order,lli n,lli mid,vp &pairs){
    vll mark(n,0),prefixSum(n,0);
    f(i,mid){
        mark[order[i]]=1;
    }
    prefixSum[0]=mark[0];
    ff(1,n,1) prefixSum[i]=prefixSum[i-1]+mark[i];
    fa(pairs){
        lli l=it.first,r=it.second;
        lli sum=prefixSum[r];
        if(l>0) sum-=prefixSum[l-1];
        lli len=r-l+1;
        if(sum>len/2){
            return true;
        }
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
        lli m,n;
        cin>>n>>m;
        vp pairs;
        f(i,m){
            lli l,r;
            cin>>l>>r;
            l--,r--;
            pairs.push_back({l,r});
        }
        lli q;
        cin>>q;
        vll order(q);
        f(i,q){
            lli x;
            cin>>x;
            order[i]=x-1;
        }
        vll mark(n,0),prefixSum(n,0);
        fa(order) mark[it]=1;
        prefixSum[0]=mark[0];
        ff(1,n,1) prefixSum[i]=prefixSum[i-1]+mark[i];
        bool flag=false;
        fa(pairs){
            lli l=it.first,r=it.second;
            lli sum=prefixSum[r];
            if(l>0) sum-=prefixSum[l-1];
            lli len=r-l+1;
            if(sum>len/2){
                flag=true;
                break;
            }
        }
        if(!flag) cout<<-1<<"\n";
        else{
            lli l=1,h=q,mid;
            while(h-l>1){
                mid=(l+h)>>1;
                if(check(order,n,mid,pairs)) h=mid;
                else l=mid+1;
            }
            if(check(order,n,l,pairs)) cout<<l<<"\n";
            else cout<<h<<"\n";
        }
    }
    return 0;
}