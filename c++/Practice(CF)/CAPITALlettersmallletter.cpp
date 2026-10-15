#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<lli> C(256,0),S(256,0),ans(256,0);
        f(i,n){
            if(isupper(s[i])){
                s[i]=tolower(s[i]);
                C[s[i]]++;
            }
            else{
                S[s[i]]++;
            }
        }
        lli sum=0;
        // f(i,256){
        //     if(S[i]!=0 && C[i]==0) S[i]=0;
        //     if(S[i]==0 && C[i]!=0) C[i]=0;
        // }
       
        f(i,256){
            ans[i]=min(C[i],S[i]);
            sum+=ans[i];
            C[i]-=ans[i];
            S[i]-=ans[i];
        }
        f(i,256){
            lli t=S[i]/2;
            sum+=min(k,t);
            k-=t;
            if(k<=0) break;
            lli t1=C[i]/2;
            sum+=min(k,t1);
            k-=t1;
            if(k<=0) break;
        }
        cout<<sum<<endl;
    }
    return 0;
}