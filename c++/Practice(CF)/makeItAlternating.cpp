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
const lli M=998244353; 

vll factorial(N);
void fact(){
    factorial[0]=1;
    ff(1,N,1){
        factorial[i]=(factorial[i-1]*i)%M;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    fact();
    while(t--){
        string s;
        cin>>s;
        lli n=s.size();
        lli l=0,h=0;
        vll ans;
        while(h<n-1){
            if(s[h]==s[h+1]){
                h++;
            }
            else{
                ans.push_back(h-l+1);
                h++;
                l=h;
            }
        }
        lli size=1;
        for(lli i=n-1;i>0;i--){
            if(s[i]==s[i-1]) size++;
            else break;
        }
        ans.push_back(size);
        lli ct=1;
        fa(ans){
            ct=(ct*it)%M;
        }
        if(ct==1){
            cout<<0<<" "<<ct<<endl;
        }
        else{
            lli times=0;
            fa(ans){
                times+=(it-1);
            }
            
            ct=(ct*factorial[times])%M;
            cout<<times<<" "<<ct<<endl;
        }
    }
    return 0;
}