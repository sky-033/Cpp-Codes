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
#define sor(x) sort(all(x))
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
    lli n,k;
    cin>>n>>k;
    set<lli> st,nst;
    vll a(n);
    f(i,n){
        cin>>a[i];
        st.insert(a[i]);
    }
    ff(1,n+1,1){
        if(st.find(i)==st.end()) nst.insert(i);
    }
    lli a1,a2,a3;
    if(nst.size()>=3){
        auto it=nst.begin();
        a1=*it;
        it++;
        a2=*it;
        it++;
        a3=*it;
    }
    else if(nst.size()==2){
        auto it=nst.begin();
        a1=*it;
        it++;
        a2=*it;
        a3=*st.begin();
    }
    else if(nst.size()==1){
        auto it=nst.begin();
        a1=*it;
        a3=a[n-1];
        fa(st){
            if(it!=a3){
                a2=it;
                break;
            }
        }
    }
    else{
        lli a1,a2,a3;
        a1=a[0],a3=a[n-1],a2=a[1];
    }
    f(i,k){
        if(i%3==0) cout<<a1<<" ";
        else if(i%3==1) cout<<a2<<" ";
        else cout<<a3<<" ";
    }
    cout<<endl;

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