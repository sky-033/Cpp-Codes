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
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        lli l=0,h=0;
        vll zero;
        lli ct=0;
        while(h<n){
            if(a[h]==0){
                h++;
            }
            else{
                if(h-l>=k) zero.push_back(h-l);
                h++;
                l=h;
            }
        }
        if(a[n-1]==0){
            lli count=0;
            rf(i,n){
                if(a[i]==0) count++;
                else{
                    break;
                }
            }
            if(count>=k) zero.push_back(count);
        }
        fa(zero){
            if(it==k) ct++;
            else{
                lli val=0;
                lli l=0;
                while(l<=it){
                    l+=k;
                    if(l<=it){
                        val++;
                        l++;
                    }
                    else if(l>it) break;
                }
                ct+=val;
            }
        }
        cout<<ct<<endl;
    }
    return 0;
}