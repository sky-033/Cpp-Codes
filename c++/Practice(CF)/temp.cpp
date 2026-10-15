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
    vll odd,even;
    lli maxi=-1;
    f(i,n){
        lli x;
        cin>>x;
        if(x&1){
            odd.push_back(x);
            maxi=max(maxi,x);
        }
        else even.push_back(x);
    }
    lli o=odd.size(),e=even.size();
    if(e==0){
        ff(1,n+1,1){
            if(i&1) cout<<maxi<<" ";
            else cout<<0<<" ";
        }
        return;
    }

    sort(all(odd));
    sort(all(even));
    reverse(all(even));
    
    vll preOdd(o+1,0),preEven(e+1);
    f(i,e){
        preEven[i+1]=preEven[i]+even[i];
    }
    f(i,o){
        preOdd[i+1]=preOdd[i]+odd[i];
    }
    cout<<maxi<<" ";
    ff(2,n+1,1){
        lli k=i;
        if(k-1<=e) cout<<maxi+preEven[k-1];
        else{
            if((k-e)%2==1){
                cout<<maxi+preEven[e]<<" ";
            }
            else{
                cout<<maxi+preEven[e-1]<<" ";
            }
        }
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