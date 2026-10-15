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
        string s="";
        f(i,n) s+='0';
        vll pre(n),suf(n);
        pre[0]=a[0];
        lli mini=a[0],maxi=a[n-1];
        ff(1,n,1){
            if(a[i]<mini){
                mini=a[i];
                pre[i]=mini;
            }
            else pre[i]=mini;
        }
        suf[n-1]=a[n-1];
        for(lli i=n-2;i>=0;i--){
            if(a[i]>maxi){
                suf[i]=a[i];
                maxi=a[i];
            }
            else suf[i]=maxi;
        }
        set<lli> ans;
        f(i,n){
            ans.insert(pre[i]);
            ans.insert(suf[i]);
        }
        f(i,n){
            if(ans.find(a[i])!=ans.end()) s[i]='1';
        }
        cout<<s<<endl;
    }
    return 0;
}