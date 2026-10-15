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
        lli n,x;
        cin>>n>>x;
        vll a(n);
        if(x>=n){
            f(i,n) cout<<i<<" ";
            cout<<endl;
        }
        else{
            a[n-1]=x;
            f(i,n-1){
                a[i]=i;
            }
            ff(x,n-1,1) a[i]++;
            f(i,n) cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}