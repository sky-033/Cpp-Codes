#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        lli l=0,h=1,ct=1;
        while(l<n-1){
            if(a[l]==a[h]){
                ct=max(ct,h-l+1);
                h++;
            }
            else{
                l=h;
                h++;
            }
            
        }
        // cout<<ct<<endl;
        lli ctt=0;
        lli x=n-ct;
        lli X=x;
        while(x>0){
            ctt++;
            x-=ct;
            ct*=2;
        }
        cout<<X+ctt<<endl;
    }
    return 0;
}