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

#ifndef ONLINE_JUDGE
#include "debuG.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

void solve(){
    lli n;
    cin>>n;
    string s;
    cin>>s;
    bool a=false,b=false;
    if(n%2==0){
        a=true;
        b=true;
    }
    else a=true;
    f(i,n){
        if(s[i]=='a' && a!=true){
            no;
            return;
        }
        else if(s[i]=='a' && a==true){
            if(b==false){
                b=true;
            }
            else{
                a=false;
            }
            // if(n%2==0){
            //     a=false;
            //     b=true;
            // }
            // else{
            //     a=true;
            //     b=true;
            // }
        }
        if(s[i]=='b' && b==false){
            no;
            return;
        }
        else if(s[i]=='b' && b!=false){
            if(a==false){
                a=true;
            }
            else{
                b=false;
            }
            // if(n%2==0){
            //     b=true;
            //     a=true;
            // }
            // else{
            //     a=true;
            //     b=false;
            // }
        }
        if(s[i]=='?'){
            if(!a){
                a=true;
            }
            else if(!b){
                b=true;
            }
            else{
                if(i!=n-1){
                    if(s[i+1]=='a'){
                        b=false;
                    }
                    else if(s[i+1]=='b'){
                        a=false;
                    }
                    else{
                        a=false;
                    }
                }
            }
        }
    }
    yes;
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