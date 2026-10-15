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
        vll a(n);
        f(i,n) cin>>a[i];
        bool flag=true;
        f(i,n-1){
            if(a[i]!=a[i+1]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            vll ans;
            lli maxi=-1e18,indx=-1;
            f(i,n){
                if(a[i]>maxi){
                    maxi=a[i];
                    indx=i;
                }
            }
            f(i,n){
                if(i==indx) ans.push_back(2);
                else ans.push_back(1);
            }
            f(i,n) cout<<ans[i]<<" ";
            cout<<endl;
        }

    }
    return 0;
}