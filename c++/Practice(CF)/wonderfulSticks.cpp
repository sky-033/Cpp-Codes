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
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vll v(n,0);
        lli a=1;
        for(lli i=n-2;i>=0;i--){
            if(s[i]=='<'){
                v[i+1]=a;
                a++;
            }
        }
        v[0]=a;
        a++;
        for(lli i=0;i<n-1;i++){
            if(s[i]=='>'){
                v[i+1]=a;
                a++;
            }
        }
        f(i,n) cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}