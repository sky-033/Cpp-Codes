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
    lli n,k;
    cin>>n>>k;
    vector<string> v(k);
    vector<set<char>> present(n);
    f(i,k){
        cin>>v[i];
        f(j,n){
            present[j].insert(v[i][j]);
        }
    }
    vll factors;
    ff(1,n+1,1){
        if(n%i==0){
            factors.push_back(i);
            if(i*i!=n){
                factors.push_back(n/i);
            }
        }
    }
    sort(all(factors));
    fa(factors){
        string pattern="";
        bool flag=true;
        lli d=it;
        for(lli i=0;i<d;i++){
            map<char,lli> mp;
            for(lli j=i;j<n;j+=d){
                for(auto p:present[j]) mp[p]++;
            }
            char temp;
            bool try1=false;
            for(auto itt:mp){
                if(itt.second==n/d){
                    temp=itt.first;
                    try1=true;
                    break;
                }
            }
            if(try1) pattern+=temp;
            else{
                flag=false;
                break;
            }
        }
        if(flag){
            string res="";
            for(lli i=0;i<n/d;i++){
                res+=pattern;
            }
            cout<<res<<"\n";
            return;
        }
    }
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