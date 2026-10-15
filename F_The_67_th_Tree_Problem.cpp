#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;



void solve(){
    lli x,y;
    cin>>x>>y;
    if((x==0 && y%2==0) || x>y){
        no;
        return;
    }
    if((x+y)%2==0) x--;
    else y--;
    vp edge;
    lli ex=1,ey=2;
    f(i,2*x) edge.push_back({ex++,ey++});
    f(i,y-x) edge.push_back({1,ey++});
    yes;
    fa(edge) cout<<it.first<<" "<<it.second<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}