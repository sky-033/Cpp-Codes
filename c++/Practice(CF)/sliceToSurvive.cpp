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
        lli n,m,a,b;
        cin>>n>>m>>a>>b;
        lli N=n,M=m,A=a,B=b;
        lli a1=n-a,a2=a-1,a3=m-b,a4=b-1;
        lli maxi1=max(a1,a2),maxi2=max(a3,a4);
        lli ct1=0,ct2=0;
        
            n-=maxi1;
            ct1++;
            while(m>1){
                m-=m/2;
                ct1++;
            }
            while(n>1){
                n-=n/2;
                ct1++;
            }
            
        
        
            M-=maxi2;
            ct2++;
            while(M>1){
                M-=M/2;
                ct2++;
            }
            while(N>1){
                N-=N/2;
                ct2++;
            }
            
        cout<<min(ct1,ct2)<<endl;
    }
    return 0;
}