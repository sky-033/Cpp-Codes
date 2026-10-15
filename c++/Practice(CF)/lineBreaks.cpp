#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
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
        vector<string> s(n);
        vll sizes(n),prefix_size(n);
        f(i,n){
            string str;
            cin>>str;
            s[i]=str;
        }
        f(i,n){
            sizes[i]=s[i].size();
        }
        prefix_size[0]=sizes[0];
        ff(1,n,1){
            prefix_size[i]=prefix_size[i-1]+sizes[i];
        }
        lli ct=0;
        f(i,n){
            if(prefix_size[i]<=m) ct++;
            else break;
        }
        cout<<ct<<endl;

    }
    return 0;
}