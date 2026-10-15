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
    lli x,y;
    cin>>x>>y;
    lli min_dist=4e18;
    lli best_p=x,best_q=y;
    // lambda to update the best solution found so far
    auto update=[&](lli cand_p,lli cand_q){
        if((cand_p&cand_q)==0){
            lli current_dist=abs(cand_p-x)+abs(cand_q-y);
            if(current_dist<min_dist){
                min_dist=current_dist;
                best_p=cand_p;
                best_q=cand_q;
            }
        }
    };
    update(x,y);
    for(lli i=29;i>=0;i--){
        // If both x and y have the i-th bit set
        if(((x>>i)&1LL)&&((y>>i)&1LL)){
            // Candidate 1: Increment x to clear bit i (Round up p)
            update(((x>>i)+1)<<i,y);
            // Candidate 2: Increment y to clear bit i (Round up q)
            update(x,((y>>i)+1)<<i);
            // Candidate 3: Truncate x at bit i and round down y (clearing bit i in q)
            update(x>>i<<i,(y>>i<<i)-1); 
            // Candidate 4: Truncate y at bit i and round down x (clearing bit i in p)
            update((x>>i<<i)-1,y>>i<< i);
        }
    }
    cout<<best_p<<" "<<best_q<<endl;
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