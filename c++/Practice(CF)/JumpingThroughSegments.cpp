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
const lli N=2e5+10;
const lli M=1e9+7; 

lli n;
vp line;
bool check(lli k){
    lli left=0,right=0;
    f(i,n){
        left=max(left-k,line[i].first);      //left side me -k karte jao  
        right=min(right+k,line[i].second);   //right side me +k karte jao
        if(left>right) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        line.resize(n);
        f(i,n){
            cin>>line[i].first>>line[i].second;
        }
        lli l=0,h=1e9,mid;
        while(h-l>1){
            mid=(l+h)/2;
            if(check(mid)) h=mid;
            else l=mid+1;
        }
        if(check(l)) cout<<l<<endl;
        else cout<<h<<endl;
    }
    return 0;
}