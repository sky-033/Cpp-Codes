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
        lli n,k,b,s;
        cin>>n>>k>>b>>s;
        vll v(n,0);
        v[0]=b*k;
        s-=v[0];
        if(s<0) cout<<-1<<endl;
        else{
            f(i,n){
                lli add=min(k-1,s);
                v[i]+=add;
                s-=add;
            }
            if(s>0) cout<<-1<<endl;
            else{
                f(i,n) cout<<v[i]<<" ";
                cout<<endl;
            }
        }
        
    }
    return 0;
}