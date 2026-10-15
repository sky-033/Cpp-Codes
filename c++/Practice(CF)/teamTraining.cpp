#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,x;
        cin>>n>>x;
        vll a(n);
        f(i,n) cin>>a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        lli l=0,r=0,ct=0;
        while(r<n){
            lli len=r-l+1;
            if(len*a[r]>=x){
                ct++;
                l=r+1;
            }
            r++;
        }
        cout<<ct<<endl;
    }
    return 0;
}