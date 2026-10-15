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
    vll a(n);
    f(i,n) cin>>a[i];
    if(n==1){
        cout<<a[0]<<endl;
        return;
    }
    if(n==2){
        if(a[0]>a[1]){
            cout<<a[0]<<endl;
            cout<<a[1]<<endl;
        }
        else{
            cout<<a[0]<<" "<<a[1]<<endl;
        }
        return;
    }
    set<lli> st;
    st.insert(a[0]);
    f(i,n){
        auto it=st.lower_bound(a[i]);
        if(it==st.begin()) st.insert(a[i]);
        else{
            it--;
            st.erase(it);
            st.insert(a[i]);
        }
    }
    set<lli> st1;
    lli siz=st.size();
    vvll vec(siz);
    vec[0].push_back(a[0]);
    st1.insert(a[0]);
    lli idx=0;
    map<lli,lli> id;
    id[a[0]]=0;
    ff(1,n,1){
        auto it=st1.lower_bound(a[i]);
        if(it==st1.begin()){
            st1.insert(a[i]);
            idx++;
            id[a[i]]=idx;
            vec[idx].push_back(a[i]);
        }
        else{
            it--;
            lli val=*it;
            st1.erase(it);
            st1.insert(a[i]);
            lli v=id[val];
            id[a[i]]=v;
            vec[v].push_back(a[i]);
            id.erase(id.find(val));
            // f(j,siz){
            //     if(vec[j].back()==val){
            //         vec[j].push_back(a[i]);
            //         break;
            //     }
            // }
        }
    }
    // debug(vec);
    f(i,siz){
        lli m=vec[i].size();
        f(j,m) cout<<vec[i][j]<<" ";
        cout<<endl;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}