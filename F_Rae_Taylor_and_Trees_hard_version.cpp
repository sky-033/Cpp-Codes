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
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
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
    vll p(n);
    f(i,n) cin>>p[i];
    lli mini=p[0];
    set<lli> st;
    vp edges;
    st.insert(p[0]);
    ff(1,n,1){
        if(p[i]>mini){
            if(st.size()>=1){
                for(auto it=st.begin();it!=st.end();){
                    if(*it<p[i]){
                        auto temp=it;
                        edges.push_back({p[i],*it});
                        ++temp;
                        st.erase(it);
                        it=temp;
                    }
                    else break;
                }
            }
        }
        mini=min(mini,p[i]);
        st.insert(mini);
    }
    // debug(st);
    if(st.size()==1){
        yes;
        fa(edges) cout<<it.first<<" "<<it.second<<endl;
    }
    else no;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}