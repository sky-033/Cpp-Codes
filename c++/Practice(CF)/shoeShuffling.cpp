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
        vll s(n);
        map<lli,lli> mpp;
        f(i,n) cin>>s[i];
        lli l=0LL,h=1LL;
        while(h<n){
            if(s[l]==s[h]){
                h++;
                mpp[s[l]]++;
            }
            else{
                l=h;
                h++;
            }
        }
        for(auto &it:mpp){
            it.second++;
        }
        lli flag=true;
        for(auto &it:mpp){
           if(it.second<2){
            flag=false;
            break;
           }
        }
        if(s[0]==s[1] && flag==true){
            lli size=mpp.size();
            lli l=0,h=0;
            while(size>0){
                h=mpp[s[l]];
                cout<<h<<" ";
                ff(1,h,1) cout<<i<<" ";
                size--;
                l=h;
                h+=mpp[s[l]];
            }
        }
    }
    return 0;
}