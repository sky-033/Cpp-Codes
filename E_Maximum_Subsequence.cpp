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

vll get_subset_sums(vll &arr, lli m){
    lli k=arr.size();
    lli num_subsets=1LL<<k;
    vll sums;
    sums.reserve(num_subsets); 
    f(mask,num_subsets){
        lli current_sum=0;
        f(j,k){
            if((mask>>j)&1){
                current_sum=(current_sum+arr[j])%m;
            }
        }
        sums.push_back(current_sum);
    }
    sort(all(sums));
    sums.erase(unique(all(sums)), sums.end());
    return sums;
}

void solve(){
    lli n,m;
    cin>>n>>m;
    vll a(n);
    f(i,n){
        cin>>a[i];
        a[i]=a[i]%m;
    }
    vll a1,a2;
    f(i,n){
        if(i<n/2) a1.push_back(a[i]);
        else a2.push_back(a[i]);
    }
    vll S1=get_subset_sums(a1,m);
    vll S2=get_subset_sums(a2,m);
    sort(all(S2));
    lli maxi=0;
    fa(S1){
        lli x=it;
        auto idx=lower_bound(all(S2),m-x);
        if(idx!=S2.begin()){
            idx--;
            maxi=max(maxi,x+*idx);
        }
        maxi=max(maxi,(x+S2.back())%m);
    }
    cout<<maxi<<endl;
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