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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
 
    if(setbits(n)==1){
        cout<<-1<<endl;
        return;
    }
    set<lli> st;
    vll vec;
    st.insert(1);
    vll p(n+1);
    p[n]=1;
    ff(2,n,1){
        lli val=1^i;
        p[i]=val;
        st.insert(val);
    }
    ff(1,n+1,1){
        if(st.find(i)==st.end()){
            p[1]=i;
            break;
        }
    }
    if(n%2==0){
        lli num=n-(1LL<<(bitlen(n)-1));
        swap(p[1],p[num]);
    }
    ff(1,n+1,1) cout<<p[i]<<" ";
    cout<<endl;
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