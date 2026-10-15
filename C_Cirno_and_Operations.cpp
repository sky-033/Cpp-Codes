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
    lli maxi=accumulate(all(a),0LL);
    while(a.size()>1){
        vll temp1,temp2;
        temp1=a,temp2=a;
        reverse(all(temp2));
        vll a1,a2;
        ff(1,temp1.size(),1) a1.push_back(temp1[i]-temp1[i-1]);
        ff(1,temp2.size(),1) a2.push_back(temp2[i]-temp2[i-1]);
        lli sum1=0,sum2=0;
        sum1=accumulate(all(a1),0LL);
        sum2=accumulate(all(a2),0LL);
        if(sum1>sum2){
            maxi=max(maxi,sum1);
            a=a1;
        }
        else{
            maxi=max(maxi,sum2);
            a=a2;
        }
    }
    cout<<maxi<<endl;
    
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

