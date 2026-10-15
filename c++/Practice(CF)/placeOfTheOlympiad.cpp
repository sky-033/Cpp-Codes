#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,m,k;
        cin>>n>>m>>k;
        int r=k%n;
        lli ct1=k/n;
        if(r!=0) ct1++;
        lli ct0=m-ct1;
        if(ct1==1){
            cout<<1<<endl;
        }
        else if(ct0==0) cout<<m<<endl;
        else{
            lli div=m/(ct0+1);
            if(m/(ct0+1)==(ct0+1)*m/(ct0+1)) cout<<div-1<<endl;
            else cout<<div<<endl;
        }
        
    }
    return 0;
}