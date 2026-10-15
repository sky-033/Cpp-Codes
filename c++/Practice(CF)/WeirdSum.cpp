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

lli sum(vll &v){
    sor(v);
    lli prefixsum=0,result=0;
    f(i,v.size()){
        result+=(v[i]*i-prefixsum);
        prefixsum+=v[i];
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    map<lli,vector<pair<lli,lli>>> mp;
    f(i,n){
        g(j,m){
            lli x;
            cin>>x;
            mp[x].push_back({i+1,j+1});
        }
    }
    lli ans=0;
    fa(mp){
        sor(it.second);
        lli s=it.second.size();
        if(s>1){
            vll rows,columns;
            for(lli i=0;i<s;i++){
                rows.push_back(it.second[i].first);
                columns.push_back(it.second[i].second);
            }
            ans+=sum(rows)+sum(columns);
        }
    }
    cout<<ans<<endl;
    return 0;
}