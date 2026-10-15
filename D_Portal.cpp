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
    lli x,y;
    cin>>x>>y;
    lli siz=y-x;
    vll a(n+2),b(n+2,0);
    f(i,n) cin>>a[i];
    lli idx=0;
    y++;
    f(i,n+2){
        if(i==x || i==y){
            continue;
        }
        b[i]=a[idx++];
    }
    lli mini=n+1;
    lli indx=-1;
    for(lli i=x+1;i<y;i++){
        if(mini>b[i]){
            mini=b[i];
            indx=i;
        }
        
    }
    vll ans;
    bool check=false;
    lli ij=-1;
    f(i,x){
        if(b[i]<mini){
            ans.push_back(b[i]);
            ij=i;
        }
        else{
            check=true;
            break;
        }
    }
    // debug(b);
    // debug(ans);
    if(check){
        ans.push_back(b[indx]);
        indx++;
        if(indx==y){
            indx=x+1;
        }
        while(true){
            if(b[indx]==mini) break;
            ans.push_back(b[indx]);
            indx++;
            if(indx==y)indx=x+1;
        }
        for(lli i=ij+1;i<x;i++) ans.push_back(b[i]);
        for(lli i=y+1;i<n+2;i++) ans.push_back(b[i]);
        // debug(ans);
    }
    else{
        lli ii=-1;
        for(lli i=y+1;i<n+2;i++){
            if(b[i]<mini){
                ii=i;
                ans.push_back(b[i]);
            }
            else break;
        }
        ans.push_back(b[indx]);
        indx++;
        if(indx==y){
            indx=x+1;
        }
        while(true){
            if(siz==1) break;
            if(b[indx]==mini) break;
            if(b[indx]!=0) ans.push_back(b[indx]);
            indx++;
            if(indx==y)indx=x+1;
        }
        if(ii!=-1) for(lli i=ii+1;i<n+2;i++) ans.push_back(b[i]);
        else{
            for(lli i=y+1;i<n+2;i++) ans.push_back(b[i]);
        }
       // debug(ans);
    }
    // debug(ans);
    fa(ans) cout<<it<<" ";
    cout<<endl;
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