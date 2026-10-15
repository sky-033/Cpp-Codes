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
        lli n,m;
        cin>>n>>m;
        vll a(n);
        map<lli,lli> hsh;
        lli ct=0;
        f(i,n){
            cin>>a[i];
            lli rem=a[i]%m;
            if(rem==0) ct=1;
            else hsh[rem]++;
        }
        fa(hsh){
            auto itt=hsh.find(m-it.first);
            if(itt!=hsh.end() && itt->second!=0){
                ct++;
                lli val1=it.second;
                lli val2=itt->second;
                if(val1!=val2){
                    lli add=max(val1,val2)-min(val1,val2)-1;
                    ct+=add;
                }
                itt->second=0;
            }
            else{
                ct+=it.second;
            }
            it.second=0;  
        }
        cout<<ct<<endl;
    }
    return 0;
}