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
        lli n,m;
        cin>>n>>m;
        vll a(m);
        f(i,m) cin>>a[i];
        map<lli,lli> freq;
        sort(a.begin(),a.end());
        f(i,m){
            freq[a[i]]++;
        }
        vvll fff(freq.size());
        f(i,freq.size()){
            fff[i].resize(2);
        }
        
    }
    return 0;
}