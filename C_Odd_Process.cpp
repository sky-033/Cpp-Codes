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
    vll odd,even,a(n);
    lli maxi=-1;
    f(i,n){
        lli x;
        cin>>x;
        if(x&1) maxi=max(maxi,x);
        a[i]=x;
    }
    lli ct=1,sum=0;
    f(i,n){
        sum+=a[i];
        if(a[i]&1){
            if(a[i]==maxi && ct==1){
                ct=0;
                continue;
            }
            odd.push_back(a[i]);
        }
        else even.push_back(a[i]);
    }
    if(n==1){
        if(a[0]%2==0) cout<<0<<endl;
        else cout<<a[0]<<endl;
        return;
    }
    lli o=odd.size(),e=even.size();
    if(e==0){
        ff(1,n+1,1){
            if(i&1) cout<<maxi<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        return;
    }

    if(o==0 && maxi==-1){
        ff(1,n+1,1) cout<<0<<" ";
        cout<<endl;
        return;
    }

    sort(all(odd));
    sort(all(even));
    reverse(all(even));
    
    vll preEven(e+1,0);
    f(i,e){
        preEven[i+1]=preEven[i]+even[i];
    }
    cout<<maxi<<" ";
    ff(2,n,1){
        lli k=i;
        if(k-1<=e) cout<<maxi+preEven[k-1]<<" ";
        else{
            if((k-e)%2==1){
                cout<<maxi+preEven[e]<<" ";
            }
            else{

                cout<<maxi+preEven[e-1]<<" ";
            }
        }
    }
    if(sum%2==0) cout<<0<<endl;
    else cout<<preEven[e]+maxi<<endl;

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