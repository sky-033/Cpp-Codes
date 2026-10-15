#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        lli ct0=0,ct1=0;
        f(i,n){
            if(a[i]=='0') ct0++;
            else ct1++;
        }
        lli ct=0;
        bool flag=true;
        for(lli i=n-1;i>=0;i--){
            // cout<<ct0<<" "<<ct1<<endl;
            if(ct%2==0){
                if(a[i]==b[i]){
                    if(a[i]=='0') ct0--;
                    else ct1--;
                }
                else{
                    if(ct0==ct1){
                        ct++;
                        if(a[i]=='0') ct1--;
                        else ct0--;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
            else{
                if(a[i]!=b[i]){
                    if(a[i]=='0') ct1--;
                    else ct0--;
                }
                else{
                    if(ct0==ct1){
                        ct++;
                        if(a[i]=='0') ct0--;
                        else ct1--;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
            }
        }
        // cout<<ct<<endl;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}