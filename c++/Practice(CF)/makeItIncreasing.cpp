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
        lli ct=0;
        bool flag=true;
        ff(2,n,1){
            if(a[i]==1) flag=false;
        }
        ff(1,n,1){
            if(a[i]==0) flag=false;
        }
        if(flag){
            for(lli i=n-2;i>=0;i--){
                while(a[i]>=a[i+1] && a[i] > 0){
                ct++;
                a[i]/=2;
                }
                if(a[i]==a[i+1]){
                    flag=false;
                    break;
                }
            }
            if(flag) cout<<ct<<endl;
            else cout<<-1<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}