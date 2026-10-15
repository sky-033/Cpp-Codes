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
        lli n,k,q;
        cin>>n>>k>>q;
        vll a(n),v;
        f(i,n) cin>>a[i];
        lli l=0,h=0;
        while(h<n){
            if(a[h]<=q){
                h++;
            }
            else{
                if((h-l)!=0) v.push_back(h-l);
                h++;
                l=h;
                
            }
        }
        v.push_back(h-l);
        lli ans=0;
        f(i,v.size()){
            lli temp=0;
            if(v[i]>=k) temp=((v[i]-k+1)*(v[i]-k+2))/2;
            ans+=temp;
        }
        cout<<ans<<endl;

    }
    return 0;
}