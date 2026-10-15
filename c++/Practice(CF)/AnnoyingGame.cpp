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

// #ifndef ONLINE_JUDGE
// #include "debuG.cpp"
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

lli maxSubarraySum(vll &a){
    lli current_sum=a[0];
    lli max_sum=a[0];

    ff(1,a.size(),1){
        current_sum=max(a[i],current_sum+a[i]);
        max_sum=max(max_sum,current_sum);

    }
    return max_sum;
}


void solve(){
    lli n,k;
    cin>>n>>k;
    vll a(n),b(n),L(n),R(n);
    f(i,n) cin>>a[i];
    f(i,n) cin>>b[i];
    if(k%2==0){
        cout<<maxSubarraySum(a)<<endl;
    }
    else{
        f(i,n){
            L[i]=(i && L[i-1]>0 ? L[i-1]:0ll)+a[i]; 
        }   
        for(lli i=n-1;i>=0;i--){
            R[i]=(i+1<n && R[i+1]>0 ? R[i+1]:0ll)+a[i];
        }
        lli maxi=-1e17;
        f(i,n){
            maxi=max(maxi,L[i]+R[i]-a[i]+b[i]);
        }
        cout<<maxi<<endl;
    }

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