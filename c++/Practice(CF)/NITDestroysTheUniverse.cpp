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
        f(i,n) cin>>a[i];
        lli low=-1,high=-1;
        bool flag=false;
        f(i,n){
            if(a[i]!=0){
                low=i;
                break;
            }
        }
        f(i,n){
            if(a[n-i-1]!=0){
                high=n-i-1;
                break;
            }
        }
        if(low==-1 && high==-1) cout<<0<<endl;
        else{
            for(lli i=low;i<high;i++){
                if(a[i]==0) flag=true;
            }
            if(flag) cout<<2<<endl;
            else cout<<1<<endl;
        }
        
        
    }
    return 0;
}