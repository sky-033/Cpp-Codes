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
    lli n;
    cin>>n;
    vll a(n);
    lli sum=0;
    map<lli,lli> freq;
    f(i,n){
        cin>>a[i];
        sum+=a[i];
        freq[a[i]]++;
    }
    lli ct=0;
    vll same;
    f(i,n){
        lli s=sum-a[i];
        lli req=s-a[i];
        auto it=freq.find(req);
        if(it!=freq.end()){
            if(it->first==a[i]){
                lli add=it->second-1;
                if(add>0){
                    same.push_back(it->first);
                }
            }
            else{
                same.push_back(it->first);
            }
        }
    }
    sor(same);
    f(i,n){
        lli val=a[i];
        bool flag=binary_search(same.begin(),same.end(),val);
        if(flag) ct++;
    }
    cout<<ct<<endl;
    f(i,n){
        lli val=a[i];
        bool flag=binary_search(same.begin(),same.end(),val);
        if(flag) cout<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}