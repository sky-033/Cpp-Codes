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
    lli n,q;
    cin>>n>>q;
    vll a(n);
    f(i,n) cin>>a[i];
    lli maxi=bitlen(*max_element(all(a)));
    lli l,r;
    cin>>l>>r;
    vvll vec(n,vll (maxi));
    vll prefix(n,0);
    prefix[0]=a[0];
    ff(1,n,1) prefix[i]=prefix[i-1]+a[i];
    f(i,n){
        f(j,maxi) vec[i][j]=0;
    }
    lli x=a[0];
    ff(1,n,1) x^=a[i];
    lli ans=prefix[n-1]-x;
    f(i,n){
        if(i==0){
            f(j,maxi){
                if(a[i]&(1LL<<j)) vec[i][j]=1;
            }
            continue;
        }
        f(j,maxi){
            if(a[i]&(1LL<<j)) vec[i][j]=vec[i-1][j]+1;
            else vec[i][j]=vec[i-1][j];
        }
    }
    lli start=0,end=0;
    lli len=n;
    bool found=false;
    f(i,n){
        lli low=i,high=n-1,mid,best_r=-1;
        if(i==0){
            while(high>=low){
                mid=(low+high)/2;
                lli num=0;
                f(j,maxi){
                    if(vec[mid][j]&1) num|=(1LL<<j);
                }
                lli val=prefix[mid]-num;
                if(val==ans){
                    best_r=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(high-i+1<len && best_r!=-1){
                len=high-i+1;
                start=i,end=best_r;
                found=true;
            }
            
        }
        else{
            while(high>=low){
                mid=(low+high)/2;
                lli num=0;
                f(j,maxi){
                    if((vec[mid][j]-vec[i-1][j])&1) num|=(1LL<<j);
                }
                lli val=prefix[mid]-prefix[i-1]-num;
                if(val==ans){
                    best_r=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            if(high-i+1<len && best_r!=-1){
                len=high-i+1;
                start=i,end=best_r;
                found=true;
            }
        }

    }
    if(!found) cout<<"1 1"<<endl;
    else cout<<start+1<<" "<<end+1<<endl;
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