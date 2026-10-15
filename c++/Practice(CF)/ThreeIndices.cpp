#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(i,a,b) for(lli i=a;i<b;i++)
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
        lli j=1,i=0,k=0;
        bool flag=false;
        while(j<n-1){
            if(a[j]>a[j-1] && a[j]>a[j+1]){
                i=j-1;
                k=j+1;
                flag=true;
                break;
            }
            else j++;
        }
        if(flag){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}