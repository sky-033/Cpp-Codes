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
        lli n;
        cin>>n;
        vll a(n);
        lli c1=0,c2=0;
        f(i,n){
            cin>>a[i];
            if(a[i]==1) c1++;
            else c2++;
        }
        if(c1>=c2 && c2%2==1) cout<<1<<endl;
        else if(c1>=c2 && c2%2==0) cout<<0<<endl;
        else if(n%2){
            int x=n/2 +1;
            int y=n/2;
            if(y%2==0) cout<<x-c1<<endl;
            else cout<<x+1-c1<<endl;
        }
        else{
            if(n/2 %2==1) cout<<n/2 +1 -c1<<endl;
            else cout<<n/2 - c1<<endl;
        }
    }
    return 0;
}