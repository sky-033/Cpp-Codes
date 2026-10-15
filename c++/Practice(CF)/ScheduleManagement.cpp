#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

bool check(lli k,vll &op){
    lli store=0;
    fa(op){
        if(k>=it){
            store+=(k-it)/2;
        }
        else{
            lli extra=it-k;
            if(store>=extra){
                store-=extra;
            }
            else return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vll a(m);
        unordered_map<lli,lli> freq;
        f(i,m){
            cin>>a[i];
            freq[a[i]]++;
        }
        vll op;
        fa(freq){
            op.push_back(it.second);
        }
        lli left=n-op.size();
        for(lli i=1;i<=left;i++) op.push_back(0);
        sor(op);
        lli l=1,h=op[n-1],mid;
        while(h-l>1){
            mid=(l+h)/2;
            if(check(mid,op)) h=mid;
            else l=mid+1;
        }
        if(check(l,op)) cout<<l<<endl;
        else cout<<h<<endl;
    }
    return 0;
}