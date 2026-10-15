#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
#define yes cout << "Yes" << '\n'
#define no cout << "No" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    vll p(n);
    f(i,n) cin>>p[i];
    string x;
    cin>>x;
    lli pos1,posn;
    if(x[0]=='1' || x[n-1]=='1'){
        cout<<-1<<endl;
        return;
    }
    f(i,n){
        if(p[i]==1) pos1=i;
        if(p[i]==n) posn=i;
    }
    string s(n,'0');
    if(max(pos1,posn)-min(pos1,posn)>1){
        for(lli i=min(pos1,posn)+1;i<max(pos1,posn);i++){
            s[i]='1';
        }
    }
    if(pos1!=0 && pos1!=1){
        lli val=p[0];
        for(lli i=1;i<pos1;i++){
            if(p[i]<val) s[i]='1';
        }
    }
    if(posn!=0 && posn!=1){
        lli val=p[0];
        for(lli i=1;i<posn;i++){
            if(p[i]>val) s[i]='1';
        }
    }
    if(pos1!=n-1 && pos1!=n-2){
        lli val=p[n-1];
        for(lli i=pos1+1;i<n-1;i++){
            if(p[i]<val) s[i]='1';
        }
    }
    if(posn!=n-1 && posn!=n-2){
        lli val=p[n-1];
        for(lli i=posn+1;i<n-1;i++){
            if(p[i]>val) s[i]='1';
        }
    }
    f(i,n){
        if(x[i]=='1' && s[i]!='1'){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<5<<endl;
    cout<<min(pos1,posn)+1<<" "<<max(pos1,posn)+1<<endl;
    cout<<min(pos1+1,1LL)<<" "<<max(pos1+1,1LL)<<endl;
    cout<<min(1LL,posn+1)<<" "<<max(1LL,posn+1)<<endl;
    cout<<min(n,pos1+1)<<" "<<max(pos1+1,n)<<endl;
    cout<<min(n,posn+1)<<" "<<max(n,posn+1)<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}