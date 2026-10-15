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
#define yes cout << "YES" << '\n'
#define no cout << "NO" << '\n'
#define endl '\n'
const lli N=2e5+10;
const lli M=1e9+7;
const lli INF=1e18;
const lli LOG=30;

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli a,n;
    cin>>a>>n;

    lli d1,d2;
    cin>>d1>>d2;
    if(d1>d2) swap(d1,d2);
    string s=to_string(a);
    lli d=s.size();
    if(a==0){
        cout<<d1<<endl;
        return;
    }
    lli idx=-1;
    fa(s){
        if((it-'0')==d1 || (it-'0')==d2){
            idx++;
        }
        else break;
    }
    string ne="";
    ff(idx+1,d,1) ne+=s[i];
    if(ne.size()==0){
        cout<<0<<endl;
        return;
    }

    lli f=ne[0]-'0';
    lli siz=ne.size();
    a=stoi(ne);
    if(f>d2){
        lli num1=0,num2=0;
        lli dig=siz+1;
        while(siz>0){
            num1=num1*10+d2;
            siz--;
        }
        while(dig>0){
            num2=num2*10+d1;
            dig--;
        }
        cout<<min(abs(a-num1),abs(a-num2))<<endl;
    }
    else if(f<d1){
        lli num1=0,num2=0;
        lli dig=siz-1;
        while(siz>0){
            num1=num1*10+d1;
            siz--;
        }
        while(dig>0){
            num2=num2*10+d2;
            dig--;
        }
        cout<<min(abs(a-num1),abs(a-num2))<<endl;
    }
    else{
        lli num1=d1,num2=d2,num3=0,num4=0;
        lli s12=siz-1;
        lli s3=siz-1,s4=siz+1;
        while(s12>0){
            num1=num1*10+d2;
            num2=num2*10+d1;
            s12--;
        }
        while(s3>0){
            num3=num3*10+d2;
            s3--;
        }
        while(s4>0){
            num4=num4*10+d1;s4--;
        }
        cout<<min({abs(a-num1),abs(a-num2),abs(a-num3),abs(a-num4)})<<endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}