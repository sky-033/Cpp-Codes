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
        lli n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;
        lli ct0=0,ct1=0;
        f(i,s.size()){
            if(s[i]=='0') ct0++;
            else ct1++;
        }
        lli ans=0;
        if(c0<c1){
            if(h<c1-c0){
                ans+=ct1*h;
                ans+=(ct0+ct1)*c0;
            }
            else{
                ans+=(ct1*c1)+(ct0*c0);
            }
        }
        else if(c1<c0){
            if(h<c0-c1){
                ans+=ct0*h;
                ans+=(ct0+ct1)*c1;
            }
            else{
                ans+=(ct1*c1)+(ct0*c0);
            }
        }
        else{
            ans+=(ct1*c1)+(ct0*c0); 
        }
        cout<<ans<<endl;
    }
    return 0;
}