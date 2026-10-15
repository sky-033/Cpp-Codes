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
    lli n;
    cin>>n;
    lli l=1,h=n,mid;
    lli a,b,ans;
    cout<<"2 1 "<<n<<endl;
    cin>>a;
    cout.flush();
    cout<<"1 1 "<<n<<endl;
    cin>>b;
    cout.flush();
    ans=a-b;
    while(h-l>1){
        lli val1,val2,ans1;
        mid=(l+h)/2;
        cout<<"2 1 "<<mid<<endl;
        cin>>val1;
        cout.flush();
        cout<<"1 1 "<<mid<<endl;
        cin>>val2;
        cout.flush();
        ans1=val1-val2;
        if(ans1==ans){
            h=mid;
        }
        else{
            l=mid+1;
        }
    }
    lli val11,val22,ans11;
    cout<<"2 1 "<<l<<endl;
    cin>>val11;
    cout.flush();
    cout<<"1 1 "<<l<<endl;
    cin>>val22;
    cout.flush();
    ans11=val11-val22;
    if(ans11==ans){
        cout<<"! "<<l-ans+1<<" "<<l<<endl;
        cout.flush();
    }
    else{
        cout<<"! "<<h-ans+1<<" "<<h<<endl;
        cout.flush();
    }
}
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}