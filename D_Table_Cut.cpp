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
    lli n,m;
    cin>>n>>m;
    lli total=0;
    vvll grid(n,vll(m));
    f(i,n){
        f(j,m){
            cin>>grid[i][j];
            total+=grid[i][j];
        }
    }
    lli half=total/2;
    lli row=-1;
    f(i,n){
        f(j,m){
            half-=grid[i][j];
            if(j==m-1 && half>=0){
                row=i;
            }
            if(half<0) break;
        }
        if(half<0) break;
    }
    lli add=0;
    f(i,row+1){
        f(j,m) add+=grid[i][j];
    }
    // debug(add);
    lli left=total/2-add;
    // debug(left);
    string ans="";
    if(left==0){
        f(i,row+1) ans+='D';
        f(i,m) ans+='R';
        f(i,n-row-1) ans+='D';
    }
    else{
        lli x=-1,y=-1;
        ff(row+1,n,1){
            for(lli j=m-1;j>=0;j--){
                left-=grid[i][j];
                if(left==0){
                    x=i,y=j;
                    break;
                }
            }
            if(x!=-1) break;
        }
        f(i,x) ans+='D';
        f(i,y) ans+='R';
        ans+='D';
        ff(y,m,1) ans+='R';
        f(i,n-x-1) ans+='D';
    }
    cout<<((total)/2)*((total+1)/2)<<endl;
    cout<<ans<<endl;

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