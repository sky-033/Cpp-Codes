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
        map<lli,lli> freq;
        f(i,n){
            lli x;
            cin>>x;
            freq[x]++;
        }
        fa(freq) cout<<it.first<<" "<<it.second<<endl;
        lli ct=0,maxi=0;
        auto it = freq.begin(); 
        ct=it->second;
        maxi=it->second;
        auto prev=it;
        ++it; 
        for (; it != freq.end(); it++,prev++) {
            if(it->first-(prev)->first==1){
                if(it->second-(prev)->second<0){
                    maxi=it->second;
                }
                else{
                    ct+=(it->second-maxi);
                    maxi=it->second;
                }
            }
            else{
                ct+=it->second;
            }
        } 
        cout<<ct<<endl;  
        
    }
    return 0;
}