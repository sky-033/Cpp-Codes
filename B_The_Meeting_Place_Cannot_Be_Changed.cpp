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

double calc(vll &x, vll &v, lli n, double point){
    double maxi=-1.0;
    f(i,n){
        double time=abs((double)x[i]-point)/(double)v[i];
        maxi=max(maxi,time);
    }
    return maxi;
}
void solve(){
    lli n;
    cin>>n;
    vll x(n),v(n);
    f(i,n) cin>>x[i];
    f(i,n) cin>>v[i];
    double left=*min_element(all(x));
    double right=*max_element(all(x));
    f(i,100){
        double m1=left+(right-left)/3.0;
        double m2=right-(right-left)/3.0;
        double val1=calc(x,v,n,m1);
        double val2=calc(x,v,n,m2);
        if(val1>=val2) left=m1;
        else right=m2;
        
    }
    cout<<fixed<<setprecision(12)<<calc(x,v,n,left)<<endl;
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